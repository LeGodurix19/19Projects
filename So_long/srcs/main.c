/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:46:21 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/17 16:52:59 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_global *all_datas)
{
	write(1, MESSAGE_END_EXIT, ft_strlen(MESSAGE_END_EXIT));
	ft_free_all(all_datas);
	return (0);
}

void	search_ber(char *file_name)
{
	int	i;

	i = ft_strlen((const char *)file_name);
	if (!(file_name[i - 1] == 'r' && file_name[i - 2] == 'e'
			&& file_name[i - 3] == 'b' && file_name[i - 4] == '.'))
	{
		write(1, "file_name.ber\n", 14);
		exit (0);
	}
}

void	check_fd(char *no_idea)
{
	int	fd;

	fd = open(no_idea, O_RDONLY);
	if (fd <= 0)
	{
		write(1, "Wrong filename\n", 15);
		exit (0);
	}
	close(fd);
}

int	compare_2(int x, int y, int x_max, int y_max)
{
	return ((!y && x <= x_max) || (!x && y <= y_max)
		|| (y == y_max - 1 && x <= x_max) || (x == x_max && y <= y_max)
		|| (!y && !x));
}

int	main(int argc, char **argv)
{
	t_global	*all_datas;

	if (argc != 2)
		return (0);
	search_ber(argv[1]);
	check_fd(argv[1]);
	all_datas = malloc(sizeof(t_global));
	if (!all_datas)
		return (0);
	all_datas->map_datas = ft_init_map_datas(argv[1]);
	all_datas->window = ft_init(all_datas->map_datas);
	print_map(all_datas->window, all_datas->map_datas);
	put_nb_move(all_datas);
	mlx_key_hook(all_datas->window->ptr_window, ft_key_hook, &all_datas);
	mlx_hook(all_datas->window->ptr_window, WINDOW_PRESS_EXIT, 0,
		ft_close, all_datas);
	mlx_loop(all_datas->window->ptr_mlx);
}
