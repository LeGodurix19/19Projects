/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:38:57 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/15 14:39:43 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

void	*ft_memcpy(void *destination, const void *source, size_t size);

void	*ft_calloc(size_t count, size_t size);

void	ft_free(char **ptr);

char	*ft_strnjoin(char const *s1, char const *s2, size_t n);

char	*ft_strndup(const char *s1, size_t n);

char	*get_next_line(int fd);

char	*ft_strtrim(char **line, int positionN);

char	*ft_return(char **statChar, int positionN, int valeurRd);

size_t	ft_strlen(const char *str);

int		ft_strchr(const char *str);

#endif
