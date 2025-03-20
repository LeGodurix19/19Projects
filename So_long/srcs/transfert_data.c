/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfert_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:12:31 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/17 16:56:20 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_t_map_datas_1(t_map_datas *map_datas)
{
	int	i;

	if (map_datas->map_init)
	{
		i = -1;
		while (++i < map_datas->coord_max->y && map_datas->map_init[i])
			free (map_datas->map_init[i]);
		free (map_datas->map_init);
	}
	if (map_datas->coord_max)
		free(map_datas->coord_max);
	if (map_datas)
		free(map_datas);
	map_datas = NULL;
	exit(0);
}

void	test_1(t_map_datas *map_datas)
{
	if (!map_datas && !map_datas->map_init)
		ft_free_t_map_datas_1 (map_datas);
}

void	test_2(t_map_datas *map_datas)
{
	if (!map_datas->coord_max)
		ft_free_t_map_datas_1 (map_datas);
}

t_map_datas	*ft_tran(char *file)
{
	char		*tmp;
	t_map_datas	*map_datas;
	int			fd;
	int			i;

	map_datas = malloc(sizeof(t_map_datas));
	map_datas->map_init = malloc(sizeof(char *) * ft_count(file));
	test_1(map_datas);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_free_t_map_datas_1 (map_datas);
	tmp = get_next_line(fd);
	i = check_gnl(tmp, map_datas);
	while (tmp)
	{
		map_datas->map_init[i++] = tmp;
		tmp = get_next_line(fd);
	}
	if (tmp)
		free(tmp);
	close(fd);
	map_datas->coord_max = malloc(sizeof(t_coord));
	test_2(map_datas);
	map_datas->coord_max->y = i;
	return (map_datas);
}

int	ft_count(char *file)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd))
		i++;
	close(fd);
	return (i);
}
