/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:56:29 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/06 00:00:54 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libftprintf.h"
#include <mlx.h>
#include <fcntl.h>

#define MAX_LINE 1000

static void	free_all_map(t_mappoint **map, int height)
{
	int	i;

	if (map == NULL)
		return ;
	i = -1;
	while (++i < height)
	{
		if (map[i] != NULL)
			free(map[i]);
	}
	free(map);
}

static void	free_all_lines(char **lines)
{
	char	**cur_line;
	char	**tmp;

	if (lines == NULL)
		return ;
	cur_line = lines;
	while (*cur_line)
	{
		tmp = cur_line + 1;
		free(*cur_line);
		cur_line = tmp;
	}
	free(lines);
}

t_mappoint **parse_lines(char **lines, int width, int height)
{
	t_mappoint	**map;
	char		**splited_line;
	int			i;
	int			j;

	map = (t_mappoint **)malloc(sizeof(t_mappoint *) * height);
	if (map == NULL)
		perror("Can't allocate memory\n");
	i = -1;
	while (++i < height)
	{
		map[i] = (t_mappoint *)malloc(sizeof(t_mappoint) * width);
		splited_line = ft_split(lines[i], ' ');
		if (splited_line == NULL)
			break;
		j = -1;
		while (++j < width)
		{
			map[i][j].x = j;
			map[i][j].y = i;
			map[i][j].z = ft_atoi(splited_line[j]);
		}
		free_all_lines(splited_line);
	}
	return (map);
}

static int	cal_width(char **lines)
{
	int		width;
	char	**splited_line;

	if (lines == NULL)
		return (0);
	splited_line = ft_split(lines[0], ' ');
	width = 0;
	while (splited_line[width])
	{
		if (splited_line[width][0] == '\n')
			break ;
		width++;
	}
	free_all_lines(splited_line);
	return (width);
}

static char	**read_file(char *file_name, int *width, int *height)
{
	int		fd;
	char	**lines;
	int		i;

	lines = (char **)malloc(sizeof(char *) * MAX_LINE);
	if (lines == NULL)
		perror("Can't allocate memory\n");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		perror("Can't open the file\n");
	i = 0;
	while (1)
	{
		lines[i] = get_next_line(fd);
		if (lines[i] == NULL)
			break ;
		if (i == 0)
			*width = cal_width(lines);
		i++;
	}
	*height = i;
	close(fd);
	return (lines);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_win(t_mappoint **map, int width, int height)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int i;
	int j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = -1;
	while(++i < width - 1)
	{
		j = -1;
		while(++j < height - 1)
		{
			line(&img, map[i][j], map[i][j + 1]);
			line(&img, map[i][j], map[i + 1][j]);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

t_map_info *init_map_info()
{
	t_map_info *new_map_info;

	new_map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (!new_map_info)
		return (NULL);
	new_map_info->max_x = INT_MIN;
	new_map_info->max_y = INT_MIN;
	new_map_info->min_x = INT_MAX;
	new_map_info->min_y = INT_MAX;
	return (new_map_info);
}

int	main(int argc, char **argv)
{
	char		**lines;
	int			width;
	int			height;
	t_mappoint	**map;
	t_map_info	*map_info;

	map_info = init_map_info();
	if (!map_info)
		exit(1);
	if (argc == 1)
		perror("No file name given.\n");
	else if (argc > 2)
		perror("Too many arguments.\n");
	else
	{
		lines = read_file(argv[1], &width, &height);
		ft_printf("width: %d, height: %d\n", width, height);
		map = parse_lines(lines, width, height);
		isometric_projection(map, map_info, width, height);
		init_win(map, width, height);
		free_all_lines(lines);
		free_all_map(map, height);
	}
	return (0);
}

__attribute__((destructor)) void destructor(void)
{
	int		status;
	char	buf[50];

	snprintf(buf, 50, "leaks %d &> leaksout", getpid());
	status = system(buf);
	if (status)
	{
		write(2, "leak!!!\n", 8);
		system("cat leaksout >/dev/stderr");
		exit(1);
	}
}
