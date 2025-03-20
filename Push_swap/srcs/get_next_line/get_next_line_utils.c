/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:39:57 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/15 14:40:25 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************ */
/*	copy size char from source in destination								*/
/* ************************************************************************ */

void	*ft_memcpy(void *destination, void *source, size_t size)
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

/* ************************************************************************ */
/*	return a string after '\n'												*/
/* ************************************************************************ */

char	*ft_strtrim(char **line, int position_n)
{
	char	*string;

	string = ft_strndup(&(*line)[position_n], ft_strlen(*line) - position_n);
	ft_free(line);
	return (string);
}

/* ************************************************************************ */
/*	copy n char from s1														*/
/* ************************************************************************ */

char	*ft_strndup(char *s1, size_t n)
{
	char	*p;
	size_t	i;

	p = malloc(sizeof(char) * (n + 1));
	if (!p)
		return (NULL);
	i = -1;
	while (++i < n)
		p[i] = s1[i];
	p[i] = '\0';
	return (p);
}

/* ************************************************************************ */
/*	return from str to \n													*/
/* ************************************************************************ */

char	*ft_return(char **stat_char, int position_n, int valeur_rd)
{
	char	*return_line;

	if (!*stat_char && valeur_rd <= 0)
		return (0);
	return_line = NULL;
	if (position_n == -1)
		position_n = ft_strlen(*stat_char);
	else
		position_n++;
	return_line = ft_strndup(*stat_char, position_n);
	if (position_n == (int)ft_strlen(*stat_char))
		ft_free(stat_char);
	else
		*stat_char = ft_strtrim(stat_char, position_n);
	return (return_line);
}
