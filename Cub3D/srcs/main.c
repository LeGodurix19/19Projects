/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogoorickx <hugogoorickx@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:21:48 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/09 23:34:53 by hugogoorick      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	ft_exit(t_datas_global *all_datas)
{
	free_all(all_datas);
	if (all_datas->mlx_ptr)
	{
		mlx_destroy_window(all_datas->mlx_ptr, all_datas->win_ptr);
		write(1, MESSAGE_END_EXIT, ft_strlen(MESSAGE_END_EXIT));
		exit (0);
	}
	return (0);
}

void	player_3d_move(t_datas_global *data, int dir)
{
	double	move_speed;

	move_speed = data->player_datas->move_speed;
	if (!dir)
		go(data->player_datas, move_speed, data->map_datas->map);
	else if (dir == 1)
		back(data->player_datas, move_speed, data->map_datas->map);
	else if (dir == 2)
		rotate(data->player_datas, data->player_datas->rot_speed, data);
	else if (dir == 3)
		lat_right(data->player_datas, move_speed, data);
	else if (dir == 4)
		lat_left(data->player_datas, move_speed, data);
}

int	main(int argc, char **argv)
{
	t_datas_global	all_datas;
	int				fd;
	int				tmp;

	fd = first_tests(argv, argc);
	malloc_all(&all_datas);
	convert_datas(fd, &all_datas);
	close(fd);
	if (!all_datas.map_datas->map)
		ft_print_error(ERROR_NOT_MAP, &all_datas);
	tmp = check_map(&all_datas);
	if (tmp == -1)
		ft_print_error(ERROR_WRONG_CHAR, &all_datas);
	else if (tmp == -2)
		ft_print_error(ERROR_WRONG_POS, &all_datas);
	mlx_hook(all_datas.win_ptr, 2, 0, ft_key_press, &all_datas);
	mlx_hook(all_datas.win_ptr, 3, 0, ft_key_realese, &all_datas);
	mlx_hook(all_datas.win_ptr, WINDOW_PRESS_EXIT, 0, ft_exit, &all_datas);
	mlx_loop_hook(all_datas.mlx_ptr, ft_key_hook, &all_datas);
	mlx_loop(all_datas.mlx_ptr);
}
