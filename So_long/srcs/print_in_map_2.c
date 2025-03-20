/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:12:04 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:12:06 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_pic_win_24(t_window *window, char *file_name, int x, int y)
{
	int		size;
	void	*test1;
	void	*ptr_window;
	void	*ptr_mlx;

	size = 24;
	ptr_window = window->ptr_window;
	ptr_mlx = window->ptr_mlx;
	test1 = mlx_xpm_file_to_image (ptr_mlx, file_name, &size, &size);
	mlx_put_image_to_window(ptr_mlx, ptr_window, test1, x * size, y * size);
}

void	ft_print_trap(t_global *all_datas)
{
	int	x;
	int	y;

	if (all_datas->map_datas->nb_item == all_datas->map_datas->item_max)
	{
		y = -1;
		while (++y < all_datas->map_datas->coord_max->y)
		{
			x = -1;
			while (++x < all_datas->map_datas->coord_max->x)
			{
				if (all_datas->map_datas->map_opti[y][x] == 'K')
					ft_put_image(all_datas, x, y, TRAPDOOR_OPEN);
			}
		}
		x = all_datas->map_datas->coord_player->x;
		y = all_datas->map_datas->coord_player->y;
		if (all_datas->map_datas->map_init[y][x] == 'E')
		{
			write(1, MESSAGE_END_WIN, ft_strlen(MESSAGE_END_WIN));
			ft_free_all(all_datas);
		}
	}
}

void	print_pic_win_16(t_window *window, char *file_name, int x, int y)
{
	int		size;
	void	*test1;
	void	*ptr_window;
	void	*ptr_mlx;

	size = 16;
	ptr_window = window->ptr_window;
	ptr_mlx = window->ptr_mlx;
	test1 = mlx_xpm_file_to_image (ptr_mlx, file_name, &size, &size);
	mlx_put_image_to_window(ptr_mlx, ptr_window, test1, x * 24, y * 24);
}

void	print_manip_c_e(t_global *all_datas, int x, int y)
{
	if (test_map(all_datas->map_datas->map_init[y][x]))
	{
		if (all_datas->map_datas->map_init[y][x] == 'C')
		{
			all_datas->map_datas->map_init[y][x] = '0';
			all_datas->map_datas->nb_item++;
		}
		else if (all_datas->map_datas->map_init[y][x] == 'E')
			ft_put_image(all_datas, x, y, TRAPDOOR_CLOSE);
	}
}

void	ft_put_image(t_global *all_datas, int x, int y, char *file_name)
{
	void	*ptr1;
	void	*ptr2;
	void	*test1;
	int		size;

	size = 24;
	ptr1 = all_datas->window->ptr_mlx;
	ptr2 = all_datas->window->ptr_window;
	test1 = mlx_xpm_file_to_image (ptr1, file_name, &size, &size);
	mlx_put_image_to_window(ptr1, ptr2, test1, x * size, y * size);
}
