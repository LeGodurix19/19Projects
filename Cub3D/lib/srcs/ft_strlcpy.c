/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:25:26 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/03/30 11:28:05 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	ft_strlcpy(char *dst, const char *src, int siz)
{
	int	i;
	int	len_src;

	i = 0;
	len_src = ft_strlen(src);
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
