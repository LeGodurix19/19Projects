/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:53:47 by lbuccher          #+#    #+#             */
/*   Updated: 2022/04/11 00:27:38 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	draw_vertical_line(t_datas_global *data, t_ray *data_r)
{
	t_vert_line	data_v;

	data_v.x = data->tmp2;
	data_v.i = -1;
	while (++data_v.i < SCREEN_HEIGHT)
	{
		if (data_v.i < data_r->draw_start)
			data_v.colors = (unsigned int)data->map_datas->sky;
		else if (data_v.i < data_r->draw_end)
		{
			data_r->tex_y = (int)data_r->tex_pos;
			data_r->tex_pos += data_r->step;
			data_v.colors = *(unsigned int *)(data_r->wall->addr + \
				(data_r->tex_y * data_r->wall->size_line + data_r->tex_x * \
				(data_r->wall->bpp / 8)));
		}
		else
			data_v.colors = (unsigned int)data->map_datas->floor;
		data_v.ptr = data->display_datas->addr + (data_v.i * \
			data->display_datas->size_line + data_v.x * \
			(data->display_datas->bpp / 8));
		*data_v.ptr = data_v.colors;
	}
}

void	dir_vector(t_ray *data_r, t_datas_global *data)
{
	if (data_r->ray_dir_x < 0)
	{
		data_r->step_x = -1;
		data_r->side_dist_x = (data->player_datas->x - data_r->map_x) * \
			data_r->delta_dist_x;
	}
	else
	{
		data_r->step_x = 1;
		data_r->side_dist_x = (data_r->map_x + 1.0 - data->player_datas->x) * \
			data_r->delta_dist_x;
	}
	if (data_r->ray_dir_y < 0)
	{
		data_r->step_y = -1;
		data_r->side_dist_y = (data->player_datas->y - data_r->map_y) * \
			data_r->delta_dist_y;
	}
	else
	{
		data_r->step_y = 1;
		data_r->side_dist_y = (data_r->map_y + 1.0 - data->player_datas->y) * \
			data_r->delta_dist_y;
	}
}

void	hit_wall(t_ray *data_r, t_datas_global *data)
{
	data_r->hit = 0;
	while (data_r->hit == 0)
	{
		if (data_r->side_dist_x < data_r->side_dist_y)
		{
			data_r->side_dist_x += data_r->delta_dist_x;
			data_r->map_x += data_r->step_x;
			data_r->side = 0;
		}
		else
		{
			data_r->side_dist_y += data_r->delta_dist_y;
			data_r->map_y += data_r->step_y;
			data_r->side = 1;
		}
		if (data->map_datas->map[data_r->map_y][data_r->map_x] == '1')
			data_r->hit = 1;
	}
}

void	pixel_pos(t_ray *data_r, t_datas_global *data)
{
	data_r->wall_x -= floor(data_r->wall_x);
	data_r->tex_x = (int)(data_r->wall_x * (double)data_r->tex_w);
	if (data_r->side == 0 && data_r->ray_dir_x > 0)
		data_r->tex_x = data_r->tex_w - data_r->tex_x - 1;
	if (data_r->side == 1 && data_r->ray_dir_y < 0)
		data_r->tex_x = data_r->tex_w - data_r->tex_x - 1;
	data_r->step = (double)data_r->tex_h / data_r->line_heigt;
	data_r->tex_pos = (data_r->draw_start - SCREEN_HEIGHT / 2 + \
		data_r->line_heigt / 2) * data_r->step;
	data->tmp2 = data_r->x;
}

void	create_wall(t_datas_global *data)
{
	t_ray	data_r;

	data_r.x = -1;
	while (++data_r.x < SCREEN_WIGHT)
	{
		init_ray_var(&data_r, data);
		dir_vector(&data_r, data);
		hit_wall(&data_r, data);
		init_line_size(&data_r, data);
		init_tex(&data_r, data);
		pixel_pos(&data_r, data);
		draw_vertical_line(data, &data_r);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->display_datas->ptr, 0, 0);
}
