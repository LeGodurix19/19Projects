/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:11:16 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:11:17 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_rand_player_skin(void)
{
	int	x;

	x = rand() % 5;
	if (x == 0)
		return (PLAYER0);
	else if (x == 1)
		return (PLAYER1);
	else if (x == 2)
		return (PLAYER2);
	else if (x == 3)
		return (PLAYER3);
	else if (x == 4)
		return (PLAYER4);
	return (PLAYER4);
}

void	ft_attack(t_global **ptr_all_datas)
{
	t_global	*datas;
	int			x;
	int			y;
	int			k;

	datas = *ptr_all_datas;
	x = datas->map_datas->coord_player->x;
	y = datas->map_datas->coord_player->y;
	k = 0;
	while (k < 8)
	{
		x += val_y(k, 1);
		y += val_y(k, 0);
		if (ft_compare_u_z(datas->map_datas->map_opti[y][x]))
		{
			ft_put_image(datas, x, y, FLOAR);
			datas->map_datas->map_opti[y][x] = '0';
		}
		x -= val_y(k, 1);
		y -= val_y(k, 0);
		k += 2;
	}
}

int	can_i_move(t_global	*all_datas, int x, int y)
{
	int	x_player;
	int	y_player;

	x_player = all_datas->map_datas->coord_player->x;
	y_player = all_datas->map_datas->coord_player->y;
	return (!((y == y_player && x - 2 == x_player)
			|| (y - 2 == y_player && x == x_player)
			|| (y == y_player && x + 2 == x_player)
			|| (y + 2 == y_player && x == x_player)
			|| (y == y_player && x == x_player)
			|| (y == y_player && x + 1 == x_player)
			|| (y - 1 == y_player && x == x_player)
			|| (y + 1 == y_player && x == x_player)
			|| (y - 1 == y_player && x - 1 == x_player)
			|| (y - 1 == y_player && x + 1 == x_player)
			|| (y + 1 == y_player && x - 1 == x_player)
			|| (y + 1 == y_player && x + 1 == x_player)));
}

char	*find_monster(char id_monster)
{
	if (id_monster == 'U')
		return (SPIDER);
	else if (id_monster == 'V')
		return (GOLEM);
	else if (id_monster == 'W')
		return (META);
	else if (id_monster == 'X')
		return (SATAN);
	else if (id_monster == 'Y')
		return (DUNE);
	else if (id_monster == 'Z')
		return (SCORPION);
	return (SPIDER);
}

int	ft_key_hook(int keycode, t_global **ptr_all_datas)
{
	if (keycode == ESC)
	{
		write(1, MESSAGE_END_EXIT, ft_strlen(MESSAGE_END_EXIT));
		ft_free_all(*ptr_all_datas);
	}
	else if (keycode == W || keycode == UP_ARROW)
		ft_move_player(ptr_all_datas, 1);
	else if (keycode == A || keycode == LEFT_ARROW)
		ft_move_player(ptr_all_datas, 2);
	else if (keycode == S || keycode == DOWN_ARROW)
		ft_move_player(ptr_all_datas, 3);
	else if (keycode == D || keycode == RIGHT_ARROW)
		ft_move_player(ptr_all_datas, 4);
	else if (keycode == Q)
		ft_attack(ptr_all_datas);
	return (0);
}
