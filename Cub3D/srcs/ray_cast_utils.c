/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:38:46 by lbuccher          #+#    #+#             */
/*   Updated: 2022/04/10 14:17:03 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	init_ray_var(t_ray *data_r, t_datas_global *data)
{
	data_r->cam_x = (2 * data_r->x / (double) SCREEN_WIGHT) - 1;
	data_r->ray_dir_x = ray(data->player_datas, 1, data_r->cam_x);
	data_r->ray_dir_y = ray(data->player_datas, 0, data_r->cam_x);
	data_r->map_x = (int)data->player_datas->x;
	data_r->map_y = (int)data->player_datas->y;
	data_r->delta_dist_x = delta(data_r->ray_dir_y, data_r->ray_dir_x);
	data_r->delta_dist_y = delta(data_r->ray_dir_x, data_r->ray_dir_y);
	data_r->hit = 0;
}

void	init_line_size(t_ray *data_r, t_datas_global *data)
{
	if (data_r->side == 0)
		data_r->wall_dist = wd(data_r->map_x, data->player_datas->x, \
			data_r->step_x, data_r->ray_dir_x);
	else
		data_r->wall_dist = wd(data_r->map_y, data->player_datas->y, \
			data_r->step_y, data_r->ray_dir_y);
	data_r->line_heigt = (int)(SCREEN_HEIGHT / data_r->wall_dist);
	data_r->draw_start = -data_r->line_heigt / 2 + SCREEN_HEIGHT / 2;
	data_r->draw_end = data_r->line_heigt / 2 + SCREEN_HEIGHT / 2;
	if (data_r->draw_start < 0)
		data_r->draw_start = 0;
	if (data_r->draw_end >= SCREEN_HEIGHT)
		data_r->draw_end = SCREEN_HEIGHT;
}

void	init_img(t_ray *data_r, t_datas_wall *data_w)
{
	data_r->wall = data_w;
	data_r->tex_w = data_w->size_x;
	data_r->tex_h = data_w->size_y;
	data_r->img_ptr = data_w->ptr;
}

void	init_tex(t_ray *data_r, t_datas_global *data)
{
	data_r->tex_y = 0;
	if (!data_r->side && data_r->step_x == 1)
	{
		data_r->wall_x = data->player_datas->y + data_r->wall_dist * \
			data_r->ray_dir_y;
		init_img(data_r, data->map_datas->west_wall);
	}
	else if (!data_r->side)
	{
		data_r->wall_x = data->player_datas->y + data_r->wall_dist * \
			data_r->ray_dir_y;
		init_img(data_r, data->map_datas->east_wall);
	}
	else if (data_r->step_y == -1)
	{
		data_r->wall_x = data->player_datas->x + data_r->wall_dist * \
			data_r->ray_dir_x;
		init_img(data_r, data->map_datas->south_wall);
	}
	else
	{
		data_r->wall_x = data->player_datas->x + data_r->wall_dist * \
			data_r->ray_dir_x;
		init_img(data_r, data->map_datas->north_wall);
	}
}
