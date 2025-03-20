/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:22:00 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/08 13:51:41 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	copy_the_wall(t_datas_global *all_datas, char *cp, t_datas_wall *wall)
{
	int	fd;

	if (wall->ptr)
		ft_print_error(ERROR_TOO_MANY_IMG, all_datas);
	if (ft_strlen(cp) <= 4 || cp[ft_strlen(cp) - 1] != 'M'
		|| cp[ft_strlen(cp) - 2] != 'P' || cp[ft_strlen(cp) - 3] != 'X'
		|| cp[ft_strlen(cp) - 4] != '.')
		ft_print_error(ERROR_WRONG_TYPE_IMG, all_datas);
	fd = open (cp, O_RDONLY);
	if (fd <= 0)
		ft_print_error(ERROR_IMG_NOT_EXIST, all_datas);
	close(fd);
	wall->ptr = mlx_xpm_file_to_image(all_datas->mlx_ptr, cp, \
		&wall->size_x, &wall->size_y);
	wall->addr = mlx_get_data_addr(wall->ptr, &wall->bpp, \
		&wall->size_line, &wall->endian);
}

unsigned int	copy_the_other(char *params, t_datas_global *all_datas)
{
	unsigned int	x;
	char			**mat;

	mat = ft_split(params, ',');
	if (ft_matrixlen(mat) != 3)
	{
		ft_free_mat(mat);
		ft_print_error(ERROR_INV_NUMBER_COLOR, all_datas);
	}
	x = 0;
	x = (check_num(mat[0], all_datas) << 16 | check_num(mat[1], all_datas) \
		<< 8 | check_num(mat[2], all_datas));
	ft_free_mat(mat);
	return (x);
}
