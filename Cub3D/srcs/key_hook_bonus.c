/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:43:08 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/11 00:30:11 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	ft_mouse_click(int key, int x, int y, t_datas_global *all_datas)
{
	if (key == 1)
		all_datas->test->mouse_move = 1;
	else
		all_datas->test->mouse_move = 0;
	x = 0;
	y = 0;
	return (0);
}

int	ft_mouse_move(int x, int y, t_datas_global *all_datas)
{
	y = 0;
	all_datas->test->arrow_l = 0;
	all_datas->test->arrow_r = 0;
	if (x < SCREEN_WIGHT / 2 - (SCREEN_WIGHT / 10)
		&& all_datas->test->mouse_move)
		all_datas->test->arrow_l = 1;
	if (x > SCREEN_WIGHT / 2 + (SCREEN_WIGHT / 10)
		&& all_datas->test->mouse_move)
		all_datas->test->arrow_r = 1;
	return (0);
}
