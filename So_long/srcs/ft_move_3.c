/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:11:03 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:11:04 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moveq(void)
{
	if (rand() % 3 == 1)
		return (1);
	return (0);
}

int	movex(int dir, t_global	*all_datas, int x, int y)
{
	if (dir == 2 && x > 1 && all_datas->map_datas->map_opti[y][x - 1] == '0')
		return (-1);
	else if (dir == 1 && x < all_datas->map_datas->coord_max->x - 2
		&& all_datas->map_datas->map_opti[y][x + 1] == '0')
		return (1);
	return (0);
}

int	movey(int dir, t_global *all_datas, int x, int y)
{
	if (dir == 0 && y > 1 && all_datas->map_datas->map_opti[y - 1][x] == '0')
		return (-1);
	else if (dir == 3 && y < all_datas->map_datas->coord_max->y - 2
		&& all_datas->map_datas->map_opti[y + 1][x] == '0')
		return (1);
	return (0);
}

void	ft_monster_move(t_global *all_datas, int x, int y)
{
	int		x_add;
	int		y_add;
	char	*monster;
	int		dir;
	char	c;

	if (ft_compare_u_z(all_datas->map_datas->map_opti[y][x])
			&& can_i_move(all_datas, x, y) && moveq())
	{
		monster = find_monster(all_datas->map_datas->map_opti[y][x]);
		dir = rand() % 4;
		x_add = movex(dir, all_datas, x, y);
		y_add = movey(dir, all_datas, x, y);
		ft_put_image(all_datas, x, y, FLOAR);
		ft_put_image(all_datas, x + x_add, y + y_add, monster);
		c = (char)all_datas->map_datas->map_opti[y][x];
		all_datas->map_datas->map_opti[y + y_add][x + x_add] = c;
		all_datas->map_datas->map_opti[y + y_add][x + x_add] += 32;
		if (y_add || x_add)
			all_datas->map_datas->map_opti[y][x] = '0';
	}
}
