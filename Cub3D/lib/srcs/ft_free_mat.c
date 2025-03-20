/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:22:35 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/03/30 11:29:06 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	ft_free_mat(char **mat)
{
	int	x;

	x = -1;
	while (++x < ft_matrixlen(mat))
		free(mat[x]);
	free(mat);
}
