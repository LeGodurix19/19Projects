/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:09:19 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:09:24 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**********************************/
/* Init struct with nb_a and nb_b */
/**********************************/

t_all_nbs	*init(int nb_a, int nb_b)
{
	t_all_nbs	*all_nbs;

	all_nbs = malloc(sizeof(all_nbs));
	if (!all_nbs)
		return (NULL);
	all_nbs->nb_a = nb_a;
	all_nbs->nb_b = nb_b;
	return (all_nbs);
}

/*****************/
/* Do rra or rrb */
/*****************/

void	no_idea(int *a, int *b, t_all_nbs *all_nbs)
{
	if (all_nbs->nb_a >= 2)
		reverse_rotate(a, all_nbs->nb_a, 0);
	if (all_nbs->nb_b >= 2)
		reverse_rotate(b, all_nbs->nb_b, 0);
}

/************************/
/* Do move of the input */
/************************/

int	ft_part_2(int *a, int *b, t_all_nbs *all_nbs, char *str)
{
	if (ft_strcmp(str, "rra", ft_strlen(str)))
		reverse_rotate(a, all_nbs->nb_a, 0);
	else if (ft_strcmp(str, "rrb", ft_strlen(str)))
		reverse_rotate(b, all_nbs->nb_b, 0);
	else if (ft_strcmp(str, "rrr", ft_strlen(str)))
		no_idea(a, b, all_nbs);
	else
		return (0);
	return (1);
}

int	move(int *a, int *b, t_all_nbs *all_nbs, char *str)
{
	if (ft_strcmp(str, "sa", ft_strlen(str)))
		swap(a, 0);
	else if (ft_strcmp(str, "sb", ft_strlen(str)))
		swap(b, 0);
	else if (ft_strcmp(str, "pa", ft_strlen(str)))
		push_a(b, a, &all_nbs->nb_b, &all_nbs->nb_a);
	else if (ft_strcmp(str, "pb", ft_strlen(str)))
		push_a(a, b, &all_nbs->nb_a, &all_nbs->nb_b);
	else if (ft_strcmp(str, "ra", ft_strlen(str)))
		rotate(a, all_nbs->nb_a, 0);
	else if (ft_strcmp(str, "rb", ft_strlen(str)))
		rotate(b, all_nbs->nb_b, 0);
	else if (ft_strcmp(str, "rr", ft_strlen(str)))
	{
		if (all_nbs->nb_a >= 2)
			rotate(a, all_nbs->nb_a, 0);
		if (all_nbs->nb_b >= 2)
			rotate(b, all_nbs->nb_b, 0);
	}
	else
		return (ft_part_2(a, b, all_nbs, str));
	return (1);
}

/**************************************/
/* Do moves while str isn't NULL or 0 */
/*  Return ok or ko                   */
/**************************************/

void	loop_moves(int fd, int *a, int *b, int nb_a)
{
	char		*str;
	t_all_nbs	*all_nbs;

	all_nbs = init(nb_a, 0);
	if (!all_nbs)
		error();
	str = get_next_line(fd);
	while (str)
	{
		if (ft_strcmp(str, "", ft_strlen(str)))
			break ;
		if (!move(a, b, all_nbs, str))
			error();
		free(str);
		str = get_next_line(fd);
	}
	if (check_sort_final(a, all_nbs->nb_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
