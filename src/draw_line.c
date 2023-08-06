/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:28:29 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/06 01:48:24 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf.h"

void	line(t_data *img, t_mappoint dot0, t_mappoint dot1)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int x0;
	int x1;
	int y0;
	int y1;
	int err;
	int e2;

	x0 = (int)dot0.vx;
	x1 = (int)dot1.vx;
	y0 = (int)dot0.vy;
	y1 = (int)dot1.vy;
	dx = abs(x0 - x1);
	dy = abs(y0 - y1);
	sx = -1 + 2 * (x0 < x1);
	sy = -1 + 2 * (y0 < y1);
	err = dx - dy;
	while(1)
	{
		my_mlx_pixel_put(img, x0, y0, 0x00FF0000);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}