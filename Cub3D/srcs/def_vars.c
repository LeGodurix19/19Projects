/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:22:04 by lbuccher          #+#    #+#             */
/*   Updated: 2022/04/09 06:22:06 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	def_dirs(t_datas_player *player, int val1, int val2, int val3)
{
	player->dir_x = val1;
	player->dir_y = val2;
	player->plane_x = val3;
	player->plane_y = val1;
}
