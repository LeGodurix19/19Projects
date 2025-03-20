/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:10:49 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:10:50 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	max_num;
	int	max_bits;

	max_bits = 0;
	max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(int *list_a, int *list_b, int nb_a, int nb_b)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	while (++i < get_max_bits(nb_a))
	{
		j = -1;
		size = nb_a;
		while (++j < size)
		{
			if ((list_a[0] >> i) & 1)
				rotate(list_a, nb_a, 1);
			else
				push_b(list_a, list_b, &nb_a, &nb_b);
		}
		push_a_all(list_a, list_b, &nb_a, &nb_b);
	}
}

void	big_sort(int *list_a, int *list_b, int nb_a)
{
	int	nb_b;
	int	*tmp;

	nb_b = 0;
	tmp = sort(list_a, nb_a);
	sort_simply(list_a, tmp, nb_a);
	free(tmp);
	if (!check_sort(list_a, nb_a))
		exit(1);
	radix_sort(list_a, list_b, nb_a, nb_b);
}
