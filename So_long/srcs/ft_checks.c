/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:10:19 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:10:21 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	cvt(int x, int y, int x_max, int y_max)
{
	x_max--;
	y_max--;
	if (!y && x < x_max && x > 0)
		return ('A');
	if (y == y_max && x < x_max && x > 0)
		return ('A');
	if (!y && !x)
		return ('B');
	if (!y && x == x_max)
		return ('D');
	if (!x && y == y_max)
		return ('F');
	if (x == x_max && y == y_max)
		return ('G');
	if ((x == x_max && y <= y_max && y > 0) || (!x && y <= y_max && y > 0))
		return ('H');
	return ('S');
}

int	compare(int x, int y, int x_max, int y_max)
{
	return ((!y && x <= x_max) || (!x && y <= y_max)
		|| (y == y_max && x <= x_max) || (x == x_max && y <= y_max)
		|| (!y && !x));
}

int	ft_check_map_datas(t_map_datas *map_datas)
{
	char	*datas;
	int		i;
	int		stat;
	int		j;
	int		k;

	datas = "01CEP\n";
	i = -1;
	while (++i < map_datas->coord_max->y - 1)
	{
		j = -1;
		while (map_datas->map_init[i][++j])
		{
			k = -1;
			stat = 0;
			while (datas[++k])
			{
				if (datas[k] == map_datas->map_init[i][j])
					stat = 1;
			}
			if (!stat)
				return (0);
		}
	}
	return (1);
}

int	ft_check_rec(t_map_datas *map_datas)
{
	int	x_1;
	int	x_2;
	int	y;

	y = -1;
	while (++y < map_datas->coord_max->y)
	{
		x_1 = 0;
		while (map_datas->map_init[y][x_1])
			x_1++;
		if (y && x_2 != x_1)
			return (0);
		x_2 = x_1;
	}
	return (1);
}

int	ft_check_wall(t_map_datas *map_datas)
{
	int	x;
	int	y;
	int	x_max;

	x_max = 0;
	while (map_datas->map_init[0][x_max])
		x_max++;
	x_max -= 2;
	y = -1;
	while (++y < map_datas->coord_max->y)
	{
		x = -1;
		while (map_datas->map_init[y][++x])
			if (compare_2(x, y, x_max, map_datas->coord_max->y)
				&& (map_datas->map_init[y][x] != '1'))
				return (0);
	}
	return (1);
}
