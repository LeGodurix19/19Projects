/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_map_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:11:57 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:12:00 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_nb_move(t_global *all_datas)
{
	int		x;
	void	*ptr_mlx;
	void	*ptr_win;
	char	*str_out;

	x = -1;
	while (++x < all_datas->map_datas->coord_max->x - 1)
	{
		ft_put_image(all_datas, x, 0, WALL_FRONT_VIEW);
		if (x == 0)
			ft_put_image(all_datas, x, 0, CORNER_UP_LEFT);
	}
	ptr_mlx = all_datas->window->ptr_mlx;
	ptr_win = all_datas->window->ptr_window;
	str_out = ft_itoa(all_datas->map_datas->nb_move);
	mlx_string_put(ptr_mlx, ptr_win, 10, 0, 0xFFFFFF, str_out);
	free(str_out);
	ft_putnbr(all_datas->map_datas->nb_move);
	write(1, "\n", 1);
}

void	print_q_z_maj(t_window *window, t_map_datas *datas, int x, int y)
{
	if (datas->map_opti[y][x] == 'Q')
		print_pic_win_24(window, CONE, x, y);
	else if (datas->map_opti[y][x] == 'R')
		print_pic_win_24(window, CHAIR, x, y);
	else if (datas->map_opti[y][x] == 'S')
		print_pic_win_24(window, LIBRARY_1, x, y);
	else if (datas->map_opti[y][x] == 'T')
		print_pic_win_24(window, LIBRARY_2, x, y);
	else if (datas->map_opti[y][x] == 'U')
		print_pic_win_24(window, SPIDER, x, y);
	else if (datas->map_opti[y][x] == 'V')
		print_pic_win_24(window, GOLEM, x, y);
	else if (datas->map_opti[y][x] == 'W')
		print_pic_win_24(window, META, x, y);
	else if (datas->map_opti[y][x] == 'X')
		print_pic_win_24(window, SATAN, x, y);
	else if (datas->map_opti[y][x] == 'Y')
		print_pic_win_24(window, DUNE, x, y);
	else if (datas->map_opti[y][x] == 'Z')
		print_pic_win_24(window, SCORPION, x, y);
}

void	print_a_o_maj(t_window *window, t_map_datas *datas, int x, int y)
{
	if (datas->map_opti[y][x] == 'A')
		print_pic_win_24(window, WALL_FRONT_VIEW, x, y);
	else if (datas->map_opti[y][x] == 'B')
		print_pic_win_24(window, CORNER_UP_LEFT, x, y);
	else if (datas->map_opti[y][x] == 'D')
		print_pic_win_24(window, CONER_UP_RIGHT, x, y);
	else if (datas->map_opti[y][x] == 'F')
		print_pic_win_24(window, CORNER_DOWN_LEFT, x, y);
	else if (datas->map_opti[y][x] == 'G')
		print_pic_win_24(window, CORNER_DOWN_RIGHT, x, y);
	else if (datas->map_opti[y][x] == 'H')
		print_pic_win_24(window, WALL_SIDE_VIEW, x, y);
	else if (datas->map_opti[y][x] == 'I')
		print_pic_win_24(window, BARREL_3, x, y);
	else if (datas->map_opti[y][x] == 'K')
		print_pic_win_24(window, TRAPDOOR_CLOSE, x, y);
	else if (datas->map_opti[y][x] == 'L')
		print_pic_win_24(window, CARDBOARD_BOX_1, x, y);
	else if (datas->map_opti[y][x] == 'M')
		print_pic_win_24(window, CARDBOARD_BOX_2, x, y);
	else if (datas->map_opti[y][x] == 'N')
		print_pic_win_24(window, BARREL_1, x, y);
	else if (datas->map_opti[y][x] == 'O')
		print_pic_win_24(window, BARREL_1, x, y);
}

void	print_a_f_min(t_window *window, t_map_datas *datas, int x, int y)
{
	if (datas->map_opti[y][x] == 'a')
	{
		print_pic_win_24(window, FLOAR_ITEM, x, y);
		print_pic_win_16(window, KEY_1, x, y);
	}
	else if (datas->map_opti[y][x] == 'b')
	{
		print_pic_win_24(window, FLOAR_ITEM, x, y);
		print_pic_win_16(window, KEY_2, x, y);
	}
	else if (datas->map_opti[y][x] == 'c')
	{
		print_pic_win_24(window, FLOAR_ITEM, x, y);
		print_pic_win_16(window, KEY_3, x, y);
	}
	else if (datas->map_opti[y][x] == 'd')
	{
		print_pic_win_24(window, FLOAR_ITEM, x, y);
		print_pic_win_16(window, KEY_4, x, y);
	}
	else if (datas->map_opti[y][x] == 'e')
	{
		print_pic_win_24(window, FLOAR_ITEM, x, y);
		print_pic_win_16(window, KEY_5, x, y);
	}
}

void	print_floar_map(t_window *window, t_map_datas *map_datas)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map_datas->coord_max->y)
	{
		x = -1;
		while (++x < map_datas->coord_max->x)
			print_pic_win_24(window, FLOAR, x, y);
	}
}
