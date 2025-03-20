/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:08:44 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:08:55 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*return_malloc(int x)
{
	int	*a;

	a = malloc(sizeof(int) * (x));
	if (!a)
		exit (0);
	return (a);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	i;

	i = -1;
	a = return_malloc(argc - 1);
	b = return_malloc(argc - 1);
	while (++i < argc - 1)
	{
		if (!is_digit(argv[i + 1]))
			error();
		a[i] = ft_atoi(argv[i + 1]);
	}
	if (check_duplicates_nb(a, argc - 1))
		error();
	if (argc >= 3 && argc <= 6)
		little_sort(a, b, argc - 1);
	else
		big_sort(a, b, argc - 1);
	free(a);
	free(b);
	return (0);
}
