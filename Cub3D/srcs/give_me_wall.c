/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_me_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:21:51 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/08 13:59:07 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	give_me_wall(char *line, t_datas_global *all_datas)
{
	char	**mat;

	mat = ft_split_up(line);
	all_datas->tmp1 = mat;
	if (ft_matrixlen(mat) == 0)
		return (0);
	else if (ft_matrixlen(mat) == 1)
		ft_print_error(ERROR_DATA_MISSING, all_datas);
	else if (ft_matrixlen(mat) > 2)
		ft_print_error(ERROR_TOO_MANY_DATAS, all_datas);
	if (ft_strlen(mat[0]) == 2 || ft_strlen(mat[0]) == 1)
		act_wall(all_datas, mat);
	else
		ft_print_error(ERROR_DATA_INV, all_datas);
	ft_free_mat(mat);
	all_datas->tmp1 = NULL;
	return (1);
}

void	act_wall(t_datas_global *all_datas, char **mat)
{
	if (!ft_strcmp(mat[0], "NO"))
		copy_the_wall(all_datas, mat[1], all_datas->map_datas->north_wall);
	else if (!ft_strcmp(mat[0], "SO"))
		copy_the_wall(all_datas, mat[1], all_datas->map_datas->south_wall);
	else if (!ft_strcmp(mat[0], "EA"))
		copy_the_wall(all_datas, mat[1], all_datas->map_datas->east_wall);
	else if (!ft_strcmp(mat[0], "WE"))
		copy_the_wall(all_datas, mat[1], all_datas->map_datas->west_wall);
	else if (!ft_strcmp(mat[0], "F"))
	{
		if (all_datas->map_datas->floor == UINT_MAX)
			all_datas->map_datas->floor = copy_the_other(mat[1], all_datas);
		else
			ft_print_error(ERROR_MORE_COLOR, all_datas);
	}
	else if (!ft_strcmp(mat[0], "C"))
	{
		if (all_datas->map_datas->sky == UINT_MAX)
			all_datas->map_datas->sky = copy_the_other(mat[1], all_datas);
		else
			ft_print_error(ERROR_MORE_COLOR, all_datas);
	}
	else
		ft_print_error(ERROR_DATA_INV, all_datas);
}
