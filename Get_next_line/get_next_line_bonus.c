/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:36:24 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/15 14:38:43 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*statChar[OPEN_MAX];
	char		*strBuff;
	int			positionN;
	int			valeurRd;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (0);
	positionN = ft_strchr(statChar[fd]);
	strBuff = NULL;
	while (positionN == -1)
	{
		strBuff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!strBuff)
			return (0);
		valeurRd = read(fd, strBuff, BUFFER_SIZE);
		if (valeurRd <= 0)
			break ;
		statChar[fd] = ft_strnjoin(statChar[fd], strBuff, valeurRd);
		positionN = ft_strchr(statChar[fd]);
		ft_free(&strBuff);
	}
	ft_free(&strBuff);
	return (ft_return(&statChar[fd], positionN, valeurRd));
}

/* ************************************************************************ */
/*	return where \n is														*/
/* ************************************************************************ */

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

/* ************************************************************************ */
/*	malloc count * size and put 0											*/
/* ************************************************************************ */

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

/* ************************************************************************ */
/*	join 2 str and malloc len 												*/
/* ************************************************************************ */

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	lenTot;
	char	*p;

	if (!s1)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	len_s2 = n;
	lenTot = len_s1 + len_s2;
	p = (char *)malloc(sizeof(char) * (lenTot + 1));
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, len_s1);
	if (s1)
		free((void *)s1);
	ft_memcpy(p + len_s1, s2, len_s2);
	p[lenTot] = '\0';
	return (p);
}

/* ************************************************************************ */
/*	free and ptr become NULL												*/
/* ************************************************************************ */

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
