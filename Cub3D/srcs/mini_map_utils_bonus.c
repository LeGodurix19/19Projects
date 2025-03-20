/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:34:10 by lbuccher          #+#    #+#             */
/*   Updated: 2022/04/14 15:34:15 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	init_mini_d(t_mini_map *mini_d, t_datas_global *data)
{
	if (data->player_datas->x - 5 < 0)
		mini_d->start_j = abs(((int)data->player_datas->x - 5));
	else
		mini_d->x_add = data->player_datas->x - 5;
	if (data->player_datas->y - 5 < 0)
		mini_d->start_i = abs(((int)data->player_datas->y - 5));
	else
		mini_d->y_add = data->player_datas->y - 5;
}

void	init_color(t_mini_map *mini_d, t_datas_global *data)
{
	if (data->map_datas->map[mini_d->i + mini_d->y_add] \
		[mini_d->j + mini_d->x_add] == '1')
		mini_d->color = 0xFFFFFFF;
	else if (data->map_datas->map[mini_d->i + mini_d->y_add] \
		[mini_d->j + mini_d->x_add] == '0')
		mini_d->color = 0x000000;
	else
		mini_d->color = 0xFF0000;
}
