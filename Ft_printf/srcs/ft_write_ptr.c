/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:38:28 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/21 10:48:50 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	str_len(unsigned long nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}

static int	ft_putptr(unsigned long n, char *base)
{
	char	*str;
	int		len;

	len = str_len(n);
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

int	ft_write_ptr(void *ptr)
{
	unsigned long	test;

	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	test = (long long)ptr;
	write(1, "0x", 2);
	return (ft_putptr(test, "0123456789abcdef") + 2);
}
