/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogoorickx <hugogoorickx@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:40:05 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/09 23:26:08 by hugogoorick      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	go(t_datas_player *val1, double val2, char **map)
{
	int	x;
	int	y;

	x = val1->x + val1->dir_x * val2;
	y = val1->y;
	if (map[y][x] != '1')
		val1->x += val1->dir_x * val2;
	x = val1->x;
	y = val1->y + val1->dir_y * val2;
	if (map[y][x] != '1')
		val1->y += val1->dir_y * val2;
}

void	back(t_datas_player *v1, double v2, char **map)
{
	int	x;
	int	y;

	x = v1->x - v1->dir_x * v2;
	y = v1->y;
	if (map[y][x] != '1')
		v1->x -= v1->dir_x * v2;
	x = v1->x;
	y = v1->y - v1->dir_y * v2;
	if (map[y][x] != '1')
		v1->y -= v1->dir_y * v2;
}

void	rotate(t_datas_player *val1, double val2, t_datas_global *data)
{
	double	old_x;

	old_x = val1->dir_x;
	val1->dir_x = dpx(val1, val2, 1);
	val1->dir_y = dpy(val1, val2, 1, old_x);
	old_x = val1->plane_x;
	val1->plane_x = dpx(data->player_datas, val2, 0);
	val1->plane_y = dpy(val1, val2, 0, old_x);
}

void	lat_right(t_datas_player *v1, double v2, t_datas_global *data)
{
	int	x;
	int	y;

	x = v1->x + v1->plane_x * v2;
	y = v1->y;
	if (data->map_datas->map[y][x] != '1')
		v1->x += v1->plane_x * v2;
	x = v1->x;
	y = v1->y + v1->plane_y * v2;
	if (data->map_datas->map[y][x] != '1')
		v1->y += v1->plane_y * v2;
}

void	lat_left(t_datas_player *v1, double v2, t_datas_global *data)
{
	int	x;
	int	y;

	x = v1->x - v1->plane_x * v2;
	y = v1->y;
	if (data->map_datas->map[y][x] != '1')
		v1->x -= v1->plane_x * v2;
	x = v1->x;
	y = v1->y - v1->plane_y * v2;
	if (data->map_datas->map[y][x] != '1')
		v1->y -= v1->plane_y * v2;
}
