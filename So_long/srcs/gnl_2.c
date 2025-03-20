/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:11:36 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:11:37 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	*ft_strtrim(char **line, int positionN)
{
	char	*string;

	string = ft_strndup(&(*line)[positionN], ft_strlen(*line) - positionN);
	ft_free(line);
	return (string);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
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
	p = malloc(sizeof(char) * (len_tot + 1));
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, len_s1);
	if (s1)
		free((void *)s1);
	ft_memcpy(p + len_s1, s2, len_s2);
	p[len_tot] = '\0';
	return (p);
}

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
