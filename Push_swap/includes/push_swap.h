/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:11:28 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:11:30 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_all_nbs	t_all_nbs;

struct s_all_nbs
{
	int	nb_a;
	int	nb_b;
};

char	*ft_strnjoin(char *s1, char *s2, size_t n);
char	*ft_strndup(char *s1, size_t n);
char	*get_next_line(int fd);
char	*ft_strtrim(char **line, int positionN);
char	*ft_return(char **statChar, int positionN, int valeurRd);

size_t	ft_strlcpy(char *dst, char *src, size_t siz);

void	error(void);
void	little_sort(int *list_a, int *list_b, int nb_a);
void	little_sort_part_2(int *list_a, int nb_a);
void	big_sort(int *list_a, int *list_b, int nb_a);
void	sort_simply(int *list, int *sorted_list, int size);
void	copy_arr(int *dst, int *arr, int size);
void	loop_moves(int fd, int *a, int *b, int nb_a);
void	*ft_memcpy(void *destination, void *source, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	ft_free(char **ptr);
void	swap(int *list, int stat);
void	rotate(int *list, int nb, int stat);
void	reverse_rotate(int *list, int nb, int stat);
void	push_a_all(int *arr_a, int *arr_b, int *cnt_a, int *cnt_b);
void	push_b(int *a, int *b, int *nb_a, int *nb_b);
void	push_a(int *a, int *b, int *nb_a, int *nb_b);

int		compare_numbers(int *arr, int cnt);
int		find_min(int *list, int nb);
int		check_arr(int *arr, int cnt);
int		ft_atoi(const char *str);
int		is_digit(char *str);
int		*sort(int *arr, int size);
int		ft_strlen(char *str);
int		ft_strchr(char *str);
int		check_sort_final(int *a, int nb_a);
int		check_duplicates_nb(int *list, int nb);
int		check_arr(int *arr, int cnt);
int		check_sort(int *list, int nb);
int		ft_strcmp(char *s1, char *s2, int len);
#endif
