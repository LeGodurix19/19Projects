/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:36:24 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:10:40 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_line(int fd)
{
	static char	*stat_char;
	char		*str_buff;
	int			position_n;
	int			valeur_rd;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (0);
	position_n = ft_strchr(stat_char);
	str_buff = NULL;
	while (position_n == -1)
	{
		str_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!str_buff)
			return (0);
		valeur_rd = read(fd, str_buff, BUFFER_SIZE);
		if (valeur_rd <= 0)
			break ;
		stat_char = ft_strnjoin(stat_char, str_buff, valeur_rd);
		position_n = ft_strchr(stat_char);
		ft_free(&str_buff);
	}
	ft_free(&str_buff);
	return (ft_return(&stat_char, position_n, valeur_rd));
}

/* ************************************************************************ */
/*	return where \n is														*/
/* ************************************************************************ */

int	ft_strchr(char *str)
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

char	*ft_strnjoin(char *s1, char *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_tot;
	char	*p;

	if (!s1)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	len_s2 = n;
	len_tot = len_s1 + len_s2;
	p = (char *)malloc(sizeof(char) * (len_tot + 1));
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, len_s1);
	if (s1)
		free((void *)s1);
	ft_memcpy(p + len_s1, s2, len_s2);
	p[len_tot] = '\0';
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
