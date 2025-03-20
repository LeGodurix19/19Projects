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

#include "get_next_line_bonus.h"

/* ************************************************************************ */
/*	return str's len 														*/
/* ************************************************************************ */

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* ************************************************************************ */
/*	copy size char from source in destination								*/
/* ************************************************************************ */

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

/* ************************************************************************ */
/*	return a string after '\n'												*/
/* ************************************************************************ */

char	*ft_strtrim(char **line, int positionN)
{
	char	*string;

	string = ft_strndup(&(*line)[positionN], ft_strlen(*line) - positionN);
	ft_free(line);
	return (string);
}

/* ************************************************************************ */
/*	copy n char from s1														*/
/* ************************************************************************ */

char	*ft_strndup(const char *s1, size_t n)
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

char	*ft_return(char **statChar, int positionN, int valeurRd)
{
	char	*retourLine;

	if (!*statChar && valeurRd <= 0)
		return (0);
	retourLine = NULL;
	if (positionN == -1)
		positionN = ft_strlen(*statChar);
	else
		positionN++;
	retourLine = ft_strndup(*statChar, positionN);
	if (positionN == (int)ft_strlen(*statChar))
		ft_free(statChar);
	else
		*statChar = ft_strtrim(statChar, positionN);
	return (retourLine);
}
