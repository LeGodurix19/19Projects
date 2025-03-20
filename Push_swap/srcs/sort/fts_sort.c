/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:10:55 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:10:57 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *list, int nb)
{
	int	min;
	int	i;

	min = list[0];
	i = -1;
	while (++i < nb)
		if (list[i] < min)
			min = list[i];
	return (min);
}

int	compare_numbers(int *list, int nb)
{
	return (!((list[0] > list[1] && list[0] > list[nb - 1]
				&& list[1] > list[nb - 1]) || (list[0] > list[1]
				&& list[0] < list[nb - 1])));
}

void	little_sort_part_2(int *list_a, int nb_a)
{
	if (compare_numbers(list_a, nb_a))
		rotate(list_a, nb_a, 1);
	else
		swap(list_a, 1);
}

int	*sort(int *list, int size)
{
	int		i;
	int		j;
	int		*sorted_list;
	int		tmp;

	sorted_list = malloc(sizeof(int) * size);
	copy_arr(sorted_list, list, size);
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (sorted_list[i] > sorted_list[j])
			{
				tmp = sorted_list[i];
				sorted_list[i] = sorted_list[j];
				sorted_list[j] = tmp;
			}
		}
	}
	return (sorted_list);
}

void	sort_simply(int *list, int *sorted_list, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (list[i] == sorted_list[j])
			{
				list[i] = j;
				break ;
			}
		}
	}
}
