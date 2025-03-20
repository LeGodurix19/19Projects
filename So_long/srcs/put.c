/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:12:19 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:12:21 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	put_ennemi(int x)
{
	if (!x)
		return ('U');
	if (x == 1)
		return ('V');
	if (x == 2)
		return ('W');
	if (x == 3)
		return ('X');
	if (x == 4)
		return ('Y');
	return ('Z');
}

char	ft_put_in_map(t_map_datas *datas, int i, int j)
{
	if (compare(j, i, datas->coord_max->x - 1, datas->coord_max->y - 1))
	{
		if (datas->map_init[i][j] == 'E')
			return ('J');
		return (cvt(j, i, datas->coord_max->x, datas->coord_max->y));
	}
	else if (datas->map_init[i][j] == 'E')
		return ('K');
	else if (datas->map_init[i][j] == '1')
		return (put_obstacle(rand() % 9));
	else if (datas->map_init[i][j] == 'C')
		return (put_collectible(rand() % 6));
	else if (datas->map_init[i][j] == '0')
	{
		if (rand() % 11 / 10)
			return (put_ennemi(rand() % 6));
	}
	return (datas->map_init[i][j]);
}

char	put_obstacle(int x)
{
	if (x == 0)
		return ('L');
	if (x == 1)
		return ('M');
	if (x == 2)
		return ('N');
	if (x == 3)
		return ('O');
	if (x == 4)
		return ('I');
	if (x == 5)
		return ('Q');
	if (x == 6)
		return ('R');
	if (x == 7)
		return ('S');
	return ('N');
}

char	put_collectible(int x)
{
	if (x == 0)
		return ('a');
	if (x == 1)
		return ('b');
	if (x == 2)
		return ('c');
	if (x == 3)
		return ('d');
	if (x == 4)
		return ('e');
	return ('a');
}

int	check_gnl(char *str, t_map_datas *map_datas)
{
	if (!str)
	{
		free(map_datas->map_init);
		free(map_datas);
		exit (0);
	}
	return (0);
}
