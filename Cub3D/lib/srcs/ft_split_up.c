/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:24:19 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/03/30 11:29:47 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char	*strdup_p(char *start, char *end)
{
	char	*res;
	char	*iter;

	res = malloc(end - start + 1);
	iter = res;
	while (start < end)
		*iter++ = *start++;
	*iter = '\0';
	return (res);
}

char	*forward_to_whitespace(char *str)
{
	while (*str != '\0' && !ft_isspace(*str))
		str++;
	return (str);
}

char	*forward_to_non_whitespace(char *str)
{
	while (*str != '\0' && ft_isspace(*str))
		str++;
	return (str);
}

char	**ft_split_up(char *str)
{
	char	**res;
	int		i;
	char	*iter;

	i = 0;
	iter = forward_to_non_whitespace(str);
	while (*iter != '\0')
	{
		iter = forward_to_whitespace(iter);
		iter = forward_to_non_whitespace(iter);
		i++;
	}
	res = malloc(sizeof(char *) * i + 1);
	i = 0;
	iter = forward_to_non_whitespace(str);
	while (*iter != '\0')
	{
		res[i++] = strdup_p(iter, forward_to_whitespace(iter));
		iter = forward_to_whitespace(iter);
		iter = forward_to_non_whitespace(iter);
	}
	res[i] = NULL;
	return (res);
}
