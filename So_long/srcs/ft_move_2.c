/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:10:48 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:10:49 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_you_lose(t_global *all_datas, int x, int y)
{
	if (all_datas->map_datas->map_opti[y][x] >= 'U'
			&& all_datas->map_datas->map_opti[y][x] <= 'Z')
	{
		write(1, MESSAGE_END_LOSE, ft_strlen(MESSAGE_END_LOSE));
		ft_free_all(all_datas);
	}
}

void	ft_move_ennemi(t_global **ptr_all_datas)
{
	t_global	*all_datas;
	int			x;
	int			y;

	all_datas = *ptr_all_datas;
	y = -1;
	while (++y < all_datas->map_datas->coord_max->y)
	{
		x = -1;
		while (++x < all_datas->map_datas->coord_max->x)
			ft_monster_move(all_datas, x, y);
	}
	y = -1;
	while (++y < all_datas->map_datas->coord_max->y)
	{
		x = -1;
		while (++x < all_datas->map_datas->coord_max->x)
		{
			if (ft_compare_u_z_min(all_datas->map_datas->map_opti[y][x]))
				all_datas->map_datas->map_opti[y][x] -= 32;
		}
	}
}
