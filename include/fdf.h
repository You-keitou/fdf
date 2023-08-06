/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:45:50 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/06 00:01:24 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdio.h>

# define DISPLAY_WIDTH 1920
# define DISPLAY_HEIGHT 1080
typedef struct s_mappoint
{
	double		x;
	double		y;
	double		z;
	double		vx;
	double		vy;
	double		vz;
	uint32_t	color;
}	t_mappoint;

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_map_info
{
	double max_x;
	double min_x;
	double max_y;
	double min_y;
} t_map_info;

void isometric_projection(t_mappoint **map, t_map_info *map_info, int height, int width);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);

void line(t_data *img, t_mappoint dot0, t_mappoint dot1);

#endif