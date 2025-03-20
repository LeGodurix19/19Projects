/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:48:36 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/21 10:48:37 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_clean(char *str, int len)
{
	write(1, str, len);
	free(str);
}

int	ft_write_int(int n)
{
	char		*str;
	int			len;
	long int	nb;

	len = ft_int_len(n) + 1;
	if (n == 0)
		return (zero());
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	nb = n;
	str[len] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb)
	{
		str[--len] = (nb % 10 + 48);
		nb /= 10;
	}
	len = ft_strlen(str);
	ft_clean(str, len);
	return (len);
}
