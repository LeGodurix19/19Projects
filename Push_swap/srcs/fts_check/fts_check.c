/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:10:07 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:10:08 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*****************************************/
/* Check is sort, return 0 if not sorted */
/*****************************************/

int	check_sort_final(int *a, int nb_a)
{
	int	i;

	i = -1;
	while (++i < nb_a - 1)
		if (a[i] > a[i + 1])
			return (0);
	return (1);
}

/*****************************************/
/* Check is sort, return 1 if not sorted */
/*****************************************/

int	check_sort(int *list, int nb)
{
	int	i;

	i = -1;
	while (++i < nb - 1)
		if (list[i] > list[i + 1])
			return (1);
	return (0);
}

/*********************************************/
/* Check is duplicate, return 1 if duplicate */
/*********************************************/

int	check_duplicates_nb(int *list, int nb)
{
	int	tmp;
	int	n;
	int	m;

	n = -1;
	while (++n < nb - 1)
	{
		m = n;
		tmp = list[n];
		while (++m < nb)
			if (list[m] == tmp)
				return (1);
	}
	return (0);
}
