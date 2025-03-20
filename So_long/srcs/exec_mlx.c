/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:09:35 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:09:42 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	*ft_init(t_map_datas *datas)
{
	int			x;
	int			y;
	t_window	*window;

	x = datas->coord_max->x * 24;
	y = datas->coord_max->y * 24;
	window = (t_window *)malloc(sizeof(t_window));
	window->ptr_mlx = mlx_init();
	window->ptr_window = mlx_new_window(window->ptr_mlx, x, y, "So_long");
	return (window);
}

void	print_map(t_window *window, t_map_datas *map_datas)
{
	int		x;
	int		y;

	print_floar_map(window, map_datas);
	y = -1;
	while (++y < map_datas->coord_max->y)
	{
		x = -1;
		while (++x < map_datas->coord_max->x)
		{
			print_a_o_maj(window, map_datas, x, y);
			print_q_z_maj(window, map_datas, x, y);
			print_a_f_min(window, map_datas, x, y);
			if (map_datas->map_opti[y][x] == 'P' && !map_datas->coord_player)
			{
				print_pic_win_24(window, FLOAR_PLAYER, x, y);
				print_pic_win_24(window, map_datas->player_file_name, x, y);
				map_datas->coord_player = malloc(sizeof(t_coord));
				if (!map_datas->coord_player)
					ft_free_t_map_datas_2(map_datas, 1);
				map_datas->coord_player->x = x;
				map_datas->coord_player->y = y;
			}
		}
	}
}
