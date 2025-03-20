/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:11:02 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:11:05 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	little_sort(int *list_a, int *list_b, int nb_a)
{
	int	nb_b;
	int	min;
	int	*tmp;

	nb_b = 0;
	tmp = sort(list_a, nb_a);
	sort_simply(list_a, tmp, nb_a);
	free(tmp);
	while (check_sort(list_a, nb_a))
	{
		min = find_min(list_a, nb_a);
		if (list_a[0] == list_a[1] + 1 || list_a[1] == list_a[nb_a - 1] + 1)
			swap(list_a, 1);
		else if (min == list_a[0])
			push_b(list_a, list_b, &nb_a, &nb_b);
		else if (min == list_a[nb_a - 1])
			reverse_rotate(list_a, nb_a, 1);
		else if (compare_numbers(list_a, nb_a))
			rotate(list_a, nb_a, 1);
		else
			swap(list_a, 1);
	}
	push_a_all(list_a, list_b, &nb_a, &nb_b);
}
