/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:49:11 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/21 10:49:15 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_write_uint(unsigned int n)
{
	char		*str;
	int			len;

	len = ft_uint_len(n) + 1;
	if (!n)
		return (zero());
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (n)
	{
		str[--len] = (n % 10 + 48);
		n /= 10;
	}
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
