/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:11:47 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:11:48 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	*ft_start_or_end(t_map_datas *map_datas, char c)
{
	int		i;
	int		j;
	t_coord	*out;

	i = -1;
	out = malloc(sizeof(t_coord));
	if (!out)
		ft_free_t_map_datas_2(map_datas, 1);
	out->x = -1;
	while (++i < map_datas->coord_max->y)
	{
		j = -1;
		while (map_datas->map_init[i][++j])
		{
			if (map_datas->map_init[i][j] == c && out->x == -1)
			{
				out->x = j;
				out->y = i;
			}
		}
	}
	return (out);
}

int	ft_nb_item(t_map_datas *map_datas)
{
	int	i;
	int	j;
	int	stat;

	i = -1;
	stat = 0;
	while (++i < map_datas->coord_max->y)
	{
		j = -1;
		while (map_datas->map_init[i][++j])
			if (map_datas->map_init[i][j] == 'C')
				stat++;
	}
	return (stat);
}

t_map_datas	*ft_init_map_datas(char *file_name)
{
	t_map_datas	*map_datas;

	map_datas = ft_tran(file_name);
	if (!ft_all_check(map_datas))
		ft_free_t_map_datas_2(map_datas, 1);
	map_datas->item_max = ft_nb_item(map_datas);
	map_datas->coord_start = ft_start_or_end(map_datas, 'P');
	if (!map_datas->coord_start)
		ft_free_t_map_datas_2(map_datas, 1);
	map_datas->coord_exit = ft_start_or_end(map_datas, 'E');
	if (!map_datas->coord_exit)
		ft_free_t_map_datas_2(map_datas, 1);
	map_datas->coord_max->x = ft_coord_max(map_datas->map_init);
	map_datas->map_opti = ft_convert_walls(map_datas);
	if (!map_datas->map_opti)
		ft_free_t_map_datas_2(map_datas, 1);
	map_datas->nb_item = 0;
	map_datas->nb_move = 0;
	map_datas->player_file_name = ft_rand_player_skin();
	return (map_datas);
}

int	ft_coord_max(char **map_datas)
{
	int	x_max;

	x_max = 0;
	while (map_datas[0][x_max])
		x_max++;
	x_max -= 1;
	return (x_max);
}

char	**ft_convert_walls(t_map_datas *datas)
{
	int		i;
	int		j;
	char	**map;

	srand((unsigned)time(NULL));
	map = malloc(sizeof(char *) * datas->coord_max->y);
	if (!map)
		ft_free_t_map_datas_2(datas, 1);
	i = -1;
	while (++i < datas->coord_max->y)
	{
		map[i] = malloc(sizeof(char *) * datas->coord_max->x);
		if (!map[i])
			ft_free_t_map_datas_2(datas, 1);
		j = -1;
		while (datas->map_init[i][++j])
			map[i][j] = ft_put_in_map(datas, i, j);
	}
	return (map);
}
