/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:09:53 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:09:55 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**************************/
/* Copy the string in dst */
/**************************/

void	copy_arr(int *dst, int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		dst[i] = arr[i];
}

/**********************************************/
/* Copy the string in dst  and return the len */
/**********************************************/

size_t	ft_strlcpy(char *dst, char *src, size_t siz)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen((char *)src);
	if (!siz)
		return (len_src);
	while (src[i] && i < (siz - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}
