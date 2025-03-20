/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:37:23 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/09 17:36:29 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "all_inc.h"

int		ft_isspace(char c);
int		ft_strlcpy(char *dst, const char *src, int siz);
int		ft_matrixlen(char **m);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
int		ft_all_space(char *input);

char	**ft_matrixlcpy(char **matrix_in, int nb_line);
char	**ft_split(char const *s, char c);
char	**ft_split_up(char *s);

void	ft_free_mat(char **mat);

#endif