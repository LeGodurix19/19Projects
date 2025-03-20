/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:53:21 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 20:53:23 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_window
{
	void	*ptr_window;
	void	*ptr_mlx;
}	t_window;

typedef struct s_map_datas
{
	char	**map_init;
	char	**map_opti;
	int		item_max;
	int		nb_item;
	int		nb_move;
	char	*player_file_name;
	t_coord	*coord_max;
	t_coord	*coord_start;
	t_coord	*coord_exit;
	t_coord	*coord_player;
}	t_map_datas;

typedef struct t_global
{
	t_map_datas	*map_datas;
	t_window	*window;
}	t_global;

#endif
