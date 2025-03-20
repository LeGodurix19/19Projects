/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:22:05 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/10 15:40:56 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	check_num(char *string, t_datas_global *all_datas)
{
	int	output;

	output = ft_atoi(string);
	if (ft_strlen(string) == 1 && !ft_isdigit(string[0]))
		ft_print_error(ERROR_WRONG_VALUE, all_datas);
	else if (output == -1 && ft_strlen(string) > 2)
		ft_print_error(ERROR_RBG_MAX_INT, all_datas);
	else if (output < 0)
		ft_print_error(ERROR_RBG_NEG, all_datas);
	else if (output > 255)
		ft_print_error(ERROR_RGB_255, all_datas);
	else if (output == 0 && ft_strlen(string) > 1)
		ft_print_error(ERROR_RGB_MIN_INT, all_datas);
	return (output);
}

int	check_char(char x)
{
	return (x != '\0' && x != '0' && x != '1'
		&& x != 'N' && x != 'S' && x != 'E' && x != 'W');
}

int	check_begin(char **map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < ft_matrixlen(map))
	{
		x = -1;
		while (x++ < ft_strlen(map[y]))
			if (check_char(map[y][x]) && map[y][x] != ' ')
				return (-1);
	}
	return (0);
}

int	check_while(char **map, int x, int y, t_datas_global *all_datas)
{
	if ((x == 0 || y == 0 || x + 1 == ft_strlen(map[y])
			|| x >= ft_strlen(map[y + 1]) || x >= ft_strlen(map[y - 1])
			|| y + 1 == ft_matrixlen(map)) || check_char(map[y][x + 1])
		|| check_char(map[y][x - 1]) || check_char(map[y + 1][x])
		|| check_char(map[y - 1][x]))
		return (-2);
	if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
		|| map[y][x] == 'W')
	{
		if (all_datas->player_datas->dir_x > -2)
			ft_print_error(ERROR_MORE_PLAYER, all_datas);
		all_datas->player_datas->x = (float)x;
		all_datas->player_datas->y = (float)y;
		if (map[y][x] == 'N')
			def_dirs(all_datas->player_datas, 0, -1, 1);
		if (map[y][x] == 'E')
			def_dirs(all_datas->player_datas, 1, 0, 0);
		if (map[y][x] == 'S')
			def_dirs(all_datas->player_datas, 0, 1, -1);
		if (map[y][x] == 'W')
			def_dirs(all_datas->player_datas, -1, 0, 0);
		map[y][x] = '0';
	}
	return (0);
}

int	check_map(t_datas_global *all_datas)
{
	int		x;
	int		y;
	char	**map;
	char	tmp;

	map = all_datas->map_datas->map;
	if (check_begin(map) == -1)
		return (-1);
	y = -1;
	while (++y < ft_matrixlen(map))
	{
		x = -1;
		while (x++ < ft_strlen(map[y]))
		{
			tmp = map[y][x];
			if (tmp == 48 || tmp == 78 || tmp == 83 || tmp == 69 || tmp == 87)
				if (check_while(map, x, y, all_datas) == -2)
					return (-2);
		}
	}
	if (all_datas->player_datas->dir_x == -2)
		ft_print_error(ERROR_NO_PLAYER, all_datas);
	return (1);
}
