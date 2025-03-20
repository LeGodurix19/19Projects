/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:09:09 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:09:13 by hgoorick         ###   ########.fr       */
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
	if (argc == 1)
		return (0);
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
	if (read(0, NULL, 0) == 0)
		loop_moves(0, a, b, argc - 1);
	else
		loop_moves(1, a, b, argc - 1);
	free(a);
	free(b);
	return (0);
}
