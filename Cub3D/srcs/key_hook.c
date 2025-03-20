/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:43:08 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/11 00:14:28 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	ft_key_press(int keycode, t_datas_global *all_datas)
{
	if (keycode == ESC)
		ft_print_error(MESSAGE_END_EXIT, all_datas);
	if (keycode == W)
		all_datas->test->w = 1;
	if (keycode == S)
		all_datas->test->s = 1;
	if (keycode == LEFT_ARROW)
		all_datas->test->arrow_l = 1;
	if (keycode == RIGHT_ARROW)
		all_datas->test->arrow_r = 1;
	if (keycode == D)
		all_datas->test->d = 1;
	if (keycode == A)
		all_datas->test->a = 1;
	return (0);
}

int	ft_key_realese(int keycode, t_datas_global *all_datas)
{
	if (keycode == W)
		all_datas->test->w = 0;
	if (keycode == S)
		all_datas->test->s = 0;
	if (keycode == LEFT_ARROW)
		all_datas->test->arrow_l = 0;
	if (keycode == RIGHT_ARROW)
		all_datas->test->arrow_r = 0;
	if (keycode == D)
		all_datas->test->d = 0;
	if (keycode == A)
		all_datas->test->a = 0;
	return (0);
}

int	ft_key_hook(t_datas_global *all_datas)
{
	all_datas->test1++;
	if (all_datas->test->w == 1)
		player_3d_move(all_datas, 0);
	if (all_datas->test->s == 1)
		player_3d_move(all_datas, 1);
	if (all_datas->test->arrow_l == 1)
	{
		all_datas->player_datas->rot_speed = 0.05;
		player_3d_move(all_datas, 2);
	}
	if (all_datas->test->arrow_r == 1)
	{
		all_datas->player_datas->rot_speed = -0.05;
		player_3d_move(all_datas, 2);
	}
	if (all_datas->test->d == 1)
		player_3d_move(all_datas, 3);
	if (all_datas->test->a == 1)
		player_3d_move(all_datas, 4);
	create_wall(all_datas);
	return (0);
}
