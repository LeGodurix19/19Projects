/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:38:57 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:13:05 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>
# include <mlx.h>
# include <limits.h>

# include "define.h"
# include "struct.h"

t_map_datas	*ft_init_map_datas(char *file_name);
t_map_datas	*ft_tran(char *file);

char		*ft_rand_player_skin(void);
char		*ft_itoa(int n);
char		*ft_return(char **statChar, int positionN, int valeurRd);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strnjoin(char const *s1, char const *s2, size_t n);
char		*ft_strtrim(char **line, int positionN);
char		*get_next_line(int fd);
char		put_ennemi(int x);
char		ft_put_in_map(t_map_datas *datas, int i, int j);
char		put_obstacle(int x);
char		**ft_convert_walls(t_map_datas *datas);
char		cvt(int x, int y, int x_max, int y_max);
char		put_collectible(int x);
char		*find_monster(char id_monster);

void		ft_monster_move(t_global *all_datas, int x, int y);
void		ft_move_ennemi(t_global **ptr_all_datas);
void		print_manip_c_e(t_global *all_datas, int x, int y);
void		ft_put_x_y(t_global *all_datas, int x, int y);
void		ft_print_trap(t_global *all_datas);
void		do_you_lose(t_global *all_datas, int x, int y);
void		ft_global_end(t_global **ptr_datas, t_global *datas, int x, int y);
void		ft_free_t_map_datas_2(t_map_datas *map_datas, int x);
void		ft_move_ennemi(t_global **ptr_all_datas);
void		print_floar_map(t_window *window, t_map_datas *map_datas);
void		print_a_f_min(t_window *window, t_map_datas *datas, int x, int y);
void		print_q_z_maj(t_window *window, t_map_datas *datas, int x, int y);
void		print_a_o_maj(t_window *window, t_map_datas *datas, int x, int y);
void		print_pic_win_24(t_window *window, char *file_name, int x, int y);
void		print_pic_win_16(t_window *window, char *file_name, int x, int y);
void		ft_put_image(t_global *all_datas, int x, int y, char *file_name);
void		ft_putnbr(int n);
void		*ft_calloc(size_t count, size_t size);
void		ft_free(char **ptr);
void		*ft_memcpy(void *destination, const void *source, size_t size);
void		put_nb_move(t_global *all_datas);
void		ft_attack(t_global **ptr_all_datas);
void		ft_move_player(t_global **ptr_all_datas, int stat);
void		print_map(t_window *window, t_map_datas *map_datas);

int			check_gnl(char *str, t_map_datas *map_datas);
int			compare_2(int x, int y, int x_max, int y_max);
int			ft_free_all(t_global *all_datas);
int			val_y(int k, int stat);
int			movey(int dir, t_global *all_datas, int x, int y);
int			ft_compare_u_z_min(char x);
int			can_i_move(t_global	*all_datas, int x, int y);
int			moveq(void);
int			movex(int dir, t_global	*all_datas, int x, int y);
int			add_to_x(t_global *all_datas, int x, int y, int stat);
int			add_to_y(t_global *all_datas, int x, int y, int stat);
int			ft_count(char *file);
int			compare(int x, int y, int x_max, int y_max);
int			ft_strchr(const char *str);
int			ft_all_check(t_map_datas *map_datas);
int			ft_check_map_datas(t_map_datas *map_datas);
int			ft_check_rec(t_map_datas *map_datas);
int			ft_check_wall(t_map_datas *map_datas);
int			ft_coord_max(char **map_datas);
int			ft_nb_item(t_map_datas *map_datas);
int			ft_compare_u_z(char x);
int			ft_key_hook(int keycode, t_global **ptr_all_datas);
int			test_map(char x);

t_coord		*ft_start_or_end(t_map_datas *map_datas, char c);

size_t		ft_strlen(const char *str);

t_window	*ft_init(t_map_datas *datas);

#endif
