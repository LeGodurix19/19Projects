/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:25:42 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/03/30 11:27:31 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char	*ft_strjoin(char *line, char buf)
{
	int		i;
	char	*new;

	if (buf == '\n')
		return (line);
	i = 0;
	while (line && line[i])
		i++;
	new = malloc(i + 2);
	i = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	new[i++] = buf;
	new[i] = '\0';
	if (line)
		free(line);
	return (new);
}

char	*get_next_line(int fd)
{
	int		ret;
	char	*line;
	char	buf[1];

	ret = 1;
	line = 0;
	*buf = 0;
	ret = read(fd, buf, 1);
	if (*buf == '\n')
	{
		line = malloc(sizeof(char) * 2);
		line[0] = '\n';
	}
	while (ret && *buf != '\n')
	{
		if (ret == -1 || ret == 0)
			return (0);
		line = ft_strjoin(line, *buf);
		ret = read(fd, buf, 1);
	}
	return (line);
}
