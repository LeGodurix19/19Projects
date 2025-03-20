/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_fcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:45:12 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/11 00:47:10 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	*malloc_test(void *all, int nb, t_datas_global *all_datas)
{
	all = malloc(nb);
	if (!all)
		ft_print_error(ERROR_MALLOC, all_datas);
	return (all);
}

void	malloc_all_2(t_datas_global *all_datas)
{
	all_datas->map_datas = (t_datas_map *)malloc_test(all_datas->map_datas, \
		sizeof(t_datas_map), all_datas);
	all_datas->display_datas = (t_datas_display *)malloc_test(\
		all_datas->display_datas, sizeof(t_datas_display), all_datas);
	all_datas->player_datas = (t_datas_player *)malloc_test(\
		all_datas->player_datas, sizeof(t_datas_player), all_datas);
	all_datas->map_datas->north_wall = (t_datas_wall *)malloc_test(\
		all_datas->map_datas->north_wall, sizeof(t_datas_wall), all_datas);
	all_datas->map_datas->south_wall = (t_datas_wall *)malloc_test(\
		all_datas->map_datas->south_wall, sizeof(t_datas_wall), all_datas);
	all_datas->map_datas->east_wall = (t_datas_wall *)malloc_test(\
		all_datas->map_datas->east_wall, sizeof(t_datas_wall), all_datas);
	all_datas->map_datas->west_wall = (t_datas_wall *)malloc_test(\
		all_datas->map_datas->west_wall, sizeof(t_datas_wall), all_datas);
	all_datas->test = (t_test *)malloc_test(\
		all_datas->test, sizeof(t_test), all_datas);
	all_datas->sprite1 = (t_datas_wall *)malloc_test(all_datas->sprite1, \
		sizeof(t_datas_wall), all_datas);
	all_datas->sprite2 = (t_datas_wall *)malloc_test(all_datas->sprite2, \
		sizeof(t_datas_wall), all_datas);
	all_datas->sprite3 = (t_datas_wall *)malloc_test(all_datas->sprite3, \
		sizeof(t_datas_wall), all_datas);
}

void	malloc_all_3(t_datas_global *all_datas)
{
	all_datas->test->s = 0;
	all_datas->test->a = 0;
	all_datas->test->d = 0;
	all_datas->test->arrow_l = 0;
	all_datas->test->arrow_r = 0;
	all_datas->test->mouse_move = 0;
	all_datas->test1 = 0;
	all_datas->sprite1->ptr = mlx_xpm_file_to_image(all_datas->mlx_ptr, \
		"./img/img_face.xpm", &all_datas->sprite1->size_x, \
		&all_datas->sprite1->size_y);
	all_datas->sprite1->addr = mlx_get_data_addr(all_datas->sprite1->ptr, \
		&all_datas->sprite1->bpp, &all_datas->sprite1->size_line, \
		&all_datas->sprite1->endian);
	all_datas->sprite2->ptr = mlx_xpm_file_to_image(all_datas->mlx_ptr, \
		"./img/img_left.xpm", &all_datas->sprite2->size_x, \
		&all_datas->sprite2->size_y);
	all_datas->sprite2->addr = mlx_get_data_addr(all_datas->sprite2->ptr, \
		&all_datas->sprite2->bpp, &all_datas->sprite2->size_line, \
		&all_datas->sprite2->endian);
	all_datas->sprite3->ptr = mlx_xpm_file_to_image(all_datas->mlx_ptr, \
		"./img/img_right.xpm", &all_datas->sprite3->size_x, \
		&all_datas->sprite3->size_y);
	all_datas->sprite3->addr = mlx_get_data_addr(all_datas->sprite3->ptr, \
		&all_datas->sprite3->bpp, &all_datas->sprite3->size_line, \
		&all_datas->sprite3->endian);
}

void	malloc_all(t_datas_global *all_datas)
{
	malloc_all_2(all_datas);
	all_datas->map_datas->sky = UINT_MAX;
	all_datas->map_datas->floor = UINT_MAX;
	all_datas->map_datas->south_wall->ptr = NULL;
	all_datas->map_datas->east_wall->ptr = NULL;
	all_datas->map_datas->north_wall->ptr = NULL;
	all_datas->map_datas->west_wall->ptr = NULL;
	all_datas->tmp = NULL;
	all_datas->tmp1 = NULL;
	all_datas->map_datas->map = NULL;
	all_datas->player_datas->dir_x = -2;
	all_datas->player_datas->move_speed = 0.1;
	all_datas->player_datas->rot_speed = 0.05;
	all_datas->mlx_ptr = mlx_init();
	all_datas->win_ptr = mlx_new_window(all_datas->mlx_ptr, SCREEN_WIGHT, \
		SCREEN_HEIGHT, "cub3D");
	all_datas->display_datas->ptr = mlx_new_image(all_datas->mlx_ptr, \
		SCREEN_WIGHT, SCREEN_HEIGHT);
	all_datas->display_datas->addr = mlx_get_data_addr(\
		all_datas->display_datas->ptr, &all_datas->display_datas->bpp, \
		&all_datas->display_datas->size_line, \
		&all_datas->display_datas->endian);
	all_datas->test->w = 0;
	malloc_all_3(all_datas);
}
