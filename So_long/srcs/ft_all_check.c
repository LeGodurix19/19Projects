/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:31:52 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:10:07 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_start_or_end(t_map_datas *map_datas, char c)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	x = -1;
	while (++i < map_datas->coord_max->y)
	{
		j = -1;
		while (map_datas->map_init[i][++j])
		{
			if (map_datas->map_init[i][j] == c && x == -1)
			{
				x = j;
				y = i;
			}
		}
	}
	return (x);
}

int	test_map(char x)
{
	return (x == '0' || x == 'C' || x == 'P' || x == 'E');
}

int	ft_all_check(t_map_datas *map_datas)
{
	if (!ft_check_wall(map_datas))
		exit (0);
	if (!ft_check_rec(map_datas))
		exit (0);
	if (!ft_check_map_datas(map_datas))
		exit (0);
	if (!ft_nb_item(map_datas))
		exit (0);
	if (ft_check_start_or_end(map_datas, 'P') == -1)
		exit (0);
	if (ft_check_start_or_end(map_datas, 'E') == -1)
		exit (0);
	return (1);
}

int	ft_compare_u_z_min(char x)
{
	return (x >= 'u' && x <= 'z');
}

int	ft_compare_u_z(char x)
{
	return (x >= 'U' && x <= 'Z');
}
