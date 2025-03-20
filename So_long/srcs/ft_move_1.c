/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:10:35 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:10:37 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_global **ptr_all_datas, int stat)
{
	t_global	*all_datas;
	int			x;
	int			y;

	all_datas = *ptr_all_datas;
	x = all_datas->map_datas->coord_player->x;
	y = all_datas->map_datas->coord_player->y;
	ft_put_image(all_datas, x, y, FLOAR);
	print_manip_c_e(all_datas, x, y);
	if (add_to_x(all_datas, x, y, stat) || add_to_y(all_datas, x, y, stat))
	{
		if (add_to_x(all_datas, x, y, stat))
			x += add_to_x(all_datas, x, y, stat);
		else if (add_to_y(all_datas, x, y, stat))
			y += add_to_y(all_datas, x, y, stat);
		all_datas->map_datas->nb_move++;
		put_nb_move(all_datas);
	}
	ft_put_x_y(all_datas, x, y);
	ft_global_end(ptr_all_datas, all_datas, x, y);
}

int	add_to_x(t_global *all_datas, int x, int y, int stat)
{
	if (stat == 2 && x > 1
		&& (test_map(all_datas->map_datas->map_init[y][x - 1])))
		return (-1);
	else if (stat == 4 && x < all_datas->map_datas->coord_max->x - 2
		&& (test_map(all_datas->map_datas->map_init[y][x + 1])))
		return (1);
	return (0);
}

int	add_to_y(t_global *all_datas, int x, int y, int stat)
{
	if (stat == 1 && y > 1
		&& (test_map(all_datas->map_datas->map_init[y - 1][x])))
		return (-1);
	else if (stat == 3 && y < all_datas->map_datas->coord_max->y - 2
		&& (test_map(all_datas->map_datas->map_init[y + 1][x])))
		return (1);
	return (0);
}

void	ft_put_x_y(t_global *all_datas, int x, int y)
{
	all_datas->map_datas->coord_player->x = x;
	all_datas->map_datas->coord_player->y = y;
}

void	ft_global_end(t_global **ptr_datas, t_global *datas, int x, int y)
{
	if (datas->map_datas->map_init[y][x] == '0'
			|| datas->map_datas->map_init[y][x] == 'C')
		ft_put_image(datas, x, y, FLOAR);
	ft_put_image(datas, x, y, datas->map_datas->player_file_name);
	ft_move_ennemi(ptr_datas);
	do_you_lose(datas, x, y);
	ft_print_trap(datas);
}
