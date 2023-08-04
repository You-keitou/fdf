/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:56:29 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/04 17:52:12 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libftprintf.h"
#include <fcntl.h>

#define MAX_LINE 1000

// t_mappoint **parse_lines(char **lines)
// {
// 	t_mappoint	**map;
// 	char **dot_info;
// 	int j;
// 	int k;

// 	map = (t_mappoint **)malloc(sizeof(t_mappoint *) * i);
// 	if (map == NULL)
// 		return (NULL);
// 	j = 0;
// 	while (lines[j])
// 	{
// 		map[j] = (t_mappoint *)malloc(sizeof(t_mappoint) * ft_strlen(lines[j])
//			/ 2);
// 		if (map[j] == NULL)
// 			return (map);
// 		dot_info = ft_split(lines[j], ' ');
// 		if (dot_info == NULL)
// 			return (map);
// 		k = 0;
// 		while (*(dot_info + k))
// 		{
// 			map[j][k].x = k;
// 			map[j][k].y = j;
// 			map[j][k].z = ft_atoi(*(dot_info + k));
// 			map[j][k].vx = 0;
// 			map[j][k].vy = 0;
// 			map[j][k].vz = 0;
// 			map[j][k].color = 0xFFFFFF;
// 			k++;
// 		}
// 		j++;
// 	}
// 	return (map);
// }

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

int	main(int argc, char **argv)
{
	char	**lines;
	int		width;
	int		height;

	// t_mappoint **map;
	if (argc == 1)
		perror("No file name given.\n");
	else if (argc > 2)
		perror("Too many arguments.\n");
	else
	{
		lines = read_file(argv[1], &width, &height);
		ft_printf("width: %d, height: %d\n", width, height);
		free_all_lines(lines);
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
