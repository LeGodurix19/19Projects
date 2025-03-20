/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:22:03 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/09 17:37:44 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	convert_map(char *new_line, t_datas_global *all_datas)
{
	char	**tmp;

	tmp = ft_matrixlcpy(all_datas->map_datas->map, \
		ft_matrixlen(all_datas->map_datas->map));
	if (!tmp)
		ft_print_error(ERROR_MALLOC, all_datas);
	tmp[ft_matrixlen(all_datas->map_datas->map)] = \
		malloc(sizeof(char) * ft_strlen(new_line));
	if (!tmp[ft_matrixlen(all_datas->map_datas->map)])
	{
		ft_free_mat(tmp);
		ft_print_error(ERROR_MALLOC, all_datas);
	}
	ft_strlcpy(tmp[ft_matrixlen(all_datas->map_datas->map)], new_line, \
		ft_strlen(new_line) + 1);
	tmp[ft_matrixlen(all_datas->map_datas->map) + 1] = NULL;
	if (all_datas->map_datas->map)
		ft_free_mat(all_datas->map_datas->map);
	all_datas->map_datas->map = tmp;
}

void	convert_datas(int fd, t_datas_global *all_datas)
{
	int	sum;

	all_datas->tmp = get_next_line(fd);
	sum = 0;
	while (all_datas->tmp)
	{
		if (all_datas->tmp[0] != '\n' && ft_all_space(all_datas->tmp))
		{
			if (sum < 6)
				sum += give_me_wall(all_datas->tmp, all_datas);
			else
				convert_map(all_datas->tmp, all_datas);
		}
		else if (sum == 6 && all_datas->map_datas->map)
			ft_print_error(ERROR_VOID_LINE, all_datas);
		if (all_datas->tmp)
			free(all_datas->tmp);
		all_datas->tmp = get_next_line(fd);
	}
}
