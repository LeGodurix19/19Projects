/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:10:21 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:10:23 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(int *list, int nb, int stat)
{
	int	tmp;

	tmp = list[--nb];
	nb++;
	while (--nb)
		list[nb] = list[nb - 1];
	list[0] = tmp;
	if (stat)
		write(1, "rra\n", 4);
}

void	push_a_all(int *a, int *b, int *nb_a, int *nb_b)
{
	int	i;
	int	index;
	int	size;

	i = 0;
	size = *nb_b;
	while (i++ < size)
	{
		index = -1;
		while (++index < *nb_a)
			a[*nb_a - index] = a[*nb_a - index - 1];
		a[0] = b[0];
		(*nb_a)++;
		(*nb_b)--;
		index = -1;
		while (++index < *nb_b)
			b[index] = b[index + 1];
		write(1, "pa\n", 3);
	}
}

void	push_b(int *a, int *b, int *nb_a, int *nb_b)
{
	int	i;

	i = -1;
	while (++i < *nb_b)
		b[*nb_b - i] = b[*nb_b - i - 1];
	b[0] = a[0];
	(*nb_b)++;
	(*nb_a)--;
	i = -1;
	while (++i < *nb_a)
		a[i] = a[i + 1];
	write(1, "pb\n", 3);
}

void	swap(int *list, int stat)
{
	int	tmp;

	tmp = list[0];
	list[0] = list[1];
	list[1] = tmp;
	if (stat)
		write(1, "sa\n", 3);
}

void	rotate(int *list, int nb, int stat)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = list[0];
	while (++i < nb - 1)
		list[i] = list[i + 1];
	list[i] = tmp;
	if (stat)
		write(1, "ra\n", 3);
}
