/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:50:21 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/17 16:46:44 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_global *all_datas)
{
	void	*mlx;
	void	*window;

	mlx = all_datas->window->ptr_mlx;
	window = all_datas->window->ptr_window;
	mlx_destroy_window(mlx, window);
}

void	ft_free_no_idea(t_map_datas *map_datas)
{
	int	i;

	i = -1;
	while (++i < map_datas->coord_max->y)
		free (map_datas->map_init[i]);
	free (map_datas->map_init);
}

void	ft_free_t_map_datas_2(t_map_datas *map_datas, int x)
{
	int	i;

	if (map_datas->coord_start)
		free (map_datas->coord_start);
	if (map_datas->coord_exit)
		free (map_datas->coord_exit);
	if (map_datas->map_opti)
	{
		i = -1;
		while (++i < map_datas->coord_max->y)
			free (map_datas->map_opti[i]);
		free (map_datas->map_opti);
	}
	if (map_datas->map_init)
	{
		ft_free_no_idea(map_datas);
	}
	if (map_datas->coord_player)
		free (map_datas->coord_player);
	if (map_datas->coord_max)
		free (map_datas->coord_max);
	if (map_datas)
		free (map_datas);
	if (x)
		exit(0);
}

int	ft_free_all(t_global *all_datas)
{
	close_window(all_datas);
	ft_free_t_map_datas_2(all_datas->map_datas, 0);
	free(all_datas->window);
	free(all_datas);
	exit (0);
}
