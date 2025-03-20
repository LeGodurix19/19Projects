/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:11:30 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:11:32 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *)destination;
	str2 = (char *)source;
	if (!size || destination == source)
		return (destination);
	i = -1;
	while (++i < size)
		str1[i] = str2[i];
	return ((void *)destination);
}

char	*ft_return(char **stat_char, int position_n, int valeur_rd)
{
	char	*retour_line;

	if (!*stat_char && valeur_rd <= 0)
		return (0);
	retour_line = NULL;
	if (position_n == -1)
		position_n = ft_strlen(*stat_char);
	else
		position_n++;
	retour_line = ft_strndup(*stat_char, position_n);
	if (position_n == (int)ft_strlen(*stat_char))
		ft_free(stat_char);
	else
		*stat_char = ft_strtrim(stat_char, position_n);
	return (retour_line);
}

int	ft_strchr(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*rtn;
	size_t	i;

	rtn = (char *)malloc(size * count);
	if (!rtn)
		return (0);
	i = -1;
	while (++i < count)
		rtn[i] = 0;
	return (rtn);
}
