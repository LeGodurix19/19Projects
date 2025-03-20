/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:48:27 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/21 10:48:29 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_write_hex(unsigned int n, char *base)
{
	char	*str;
	int		len;

	len = ft_hex_len(n);
	if (!n)
		return (zero());
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (n && len)
	{
		str[--len] = base[n % 16];
		n /= 16;
	}
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
