/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 00:09:21 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/06 01:50:53 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void heikouidou(t_mappoint **map, t_map_info *map_info, int height, int width)
{
	int i;
	int j;
	double heikouidou_x;
	double heikouidou_y;

	heikouidou_x = (DISPLAY_WIDTH - (map_info->max_x - map_info->min_x)) / 2;
	heikouidou_y = (DISPLAY_WIDTH - (map_info->max_y - map_info->min_y)) / 2;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			map[i][j].vx = floor(map[i][j].vx + heikouidou_x);
			map[i][j].vy = floor(map[i][j].vy + heikouidou_y);
		}
	}
}

static void	zoom(t_mappoint **map, t_map_info *map_info, int height, int width)
{
	int i;
	int j;
	double bairitu;

	bairitu = DISPLAY_WIDTH / (map_info->max_x - map_info->min_x);
	if (bairitu > DISPLAY_HEIGHT / (map_info->max_y - map_info->min_y))
		bairitu = DISPLAY_HEIGHT / (map_info->max_y - map_info->min_y);
	map_info->max_x *= bairitu;
	map_info->min_x *= bairitu;
	map_info->max_y *= bairitu;
	map_info->min_y *= bairitu;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			map[i][j].vx *= bairitu;
			map[i][j].vy *= bairitu;
			map[i][j].vz *= bairitu;
		}
	}
}

void	isometric_projection(t_mappoint **map, t_map_info *map_info, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			map[i][j].vx = (map[i][j].x - map[i][j].y) / sqrt(2);
			map[i][j].vy = (map[i][j].x + map[i][j].y + 2 * map[i][j].z) / sqrt(6);
			map[i][j].vz = (-map[i][j].x - map[i][j].y +  map[i][j].z) / sqrt(3);
			if (map[i][j].vx > map_info->max_x)
				map_info->max_x = map[i][j].vx;
			if (map[i][j].vx < map_info->min_x)
				map_info->min_x = map[i][j].vx;
			if (map[i][j].vy > map_info->max_y)
				map_info->max_y = map[i][j].vy;
			if (map[i][j].vy < map_info->min_y)
				map_info->min_y = map[i][j].vy;
		}
	}
	zoom(map, map_info, height, width);
	heikouidou(map, map_info, height, width);
}
