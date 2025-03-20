/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:46:58 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/11 00:50:08 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	free_all2(t_datas_global *all_datas)
{
	if (all_datas->tmp1)
		ft_free_mat(all_datas->tmp1);
	if (all_datas->sprite1)
		free(all_datas->sprite1);
	if (all_datas->sprite2)
		free(all_datas->sprite2);
	if (all_datas->sprite3)
		free(all_datas->sprite3);
	if (all_datas->test)
		free(all_datas->test);
	if (all_datas->display_datas)
		free(all_datas->display_datas);
}

void	free_all(t_datas_global *all_datas)
{
	if (!all_datas)
		return ;
	if (all_datas->player_datas)
		free(all_datas->player_datas);
	if (all_datas->map_datas->east_wall)
		free(all_datas->map_datas->east_wall);
	if (all_datas->map_datas->north_wall)
		free(all_datas->map_datas->north_wall);
	if (all_datas->map_datas->west_wall)
		free(all_datas->map_datas->west_wall);
	if (all_datas->map_datas->south_wall)
		free(all_datas->map_datas->south_wall);
	if (all_datas->map_datas->map)
		ft_free_mat(all_datas->map_datas->map);
	if (all_datas->map_datas)
		free(all_datas->map_datas);
	if (all_datas->tmp)
		free(all_datas->tmp);
	free_all2(all_datas);
}
