/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:23:01 by lbuccher          #+#    #+#             */
/*   Updated: 2022/04/14 15:23:03 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	draw_background(t_mini_map *mini_d, t_datas_global *data)
{
	mini_d->y = -1;
	while (++mini_d->y < 80)
	{
		mini_d->x = -1;
		while (++mini_d->x < 80)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, mini_d->x, \
				mini_d->y, 0xFF0000);
	}
}

void	draw_ray(t_datas_global *data)
{
	int		color;
	float	i;
	float	x;
	float	y;

	color = 0xFF0000;
	i = -1;
	x = (8 * 10) / 2 + 4;
	y = (8 * 10) / 2 + 4;
	while (++i < 12)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(x + (data->player_datas->dir_x * i)), (y + \
				(data->player_datas->dir_y * i)), color);
}

void	draw_player(t_datas_global *data)
{
	int	x;
	int	y;

	y = ((8 * 10) / 2) - 1;
	while (++y < ((8 * 10) / 2) + 8)
	{
		x = ((8 * 10) / 2) - 1;
		while (++x < ((8 * 10) / 2) + 8)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFF0000);
	}
}

void	draw_wall_floor(t_mini_map *mini_d, t_datas_global *data)
{
	mini_d->i = -1;
	while (++mini_d->i < 10 - mini_d->start_i)
	{
		mini_d->j = -1;
		while (++mini_d->j < 10 - mini_d->start_j)
		{
			if (mini_d->i + mini_d->y_add < ft_matrixlen(data->map_datas->map)
				&& mini_d->j + mini_d->x_add < ft_strlen(data->map_datas->map \
				[mini_d->i + mini_d->y_add]))
			{
				init_color(mini_d, data);
				mini_d->y = ((mini_d->i) * 8) - 1;
				while (++mini_d->y < 8 * (mini_d->i + 1))
				{
					mini_d->x = ((mini_d->j) * 8) - 1;
					while (++mini_d->x < 8 * (mini_d->j + 1))
						mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
						mini_d->x + (mini_d->start_j * 8), mini_d->y + \
						(mini_d->start_i * 8), mini_d->color);
				}
			}
		}
	}
}

void	draw_map(t_datas_global *data)
{
	t_mini_map	mini_d;

	mini_d.start_j = 0;
	mini_d.start_i = 0;
	mini_d.y_add = 0;
	mini_d.x = 0;
	mini_d.y = 0;
	mini_d.x_add = 0;
	init_mini_d(&mini_d, data);
	draw_background(&mini_d, data);
	draw_wall_floor(&mini_d, data);
	draw_ray(data);
	draw_player(data);
}
