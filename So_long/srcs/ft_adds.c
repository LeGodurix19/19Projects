/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:09:52 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/16 22:09:54 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = 48;
	str[1] = '\0';
	return (str);
}

static int	str_len(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		i++;
	while (nbr / 10 != 0 && i++ < 10)
		nbr /= 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nb;

	len = str_len(n) + 1;
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
	return (str);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		write(0, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(0, "-", 1);
			ft_putnbr(-n);
		}
		else if (n < 10)
		{
			c = n + '0';
			write(0, &c, 1);
		}
		else
		{
			ft_putnbr(n / 10);
			c = (n % 10) + '0';
			write(0, &c, 1);
		}
	}
}

int	val_y(int k, int stat)
{
	if (k == 0 && stat == 0)
		return (1);
	if (k == 2 && stat == 0)
		return (-1);
	if (k > 3 && stat == 0)
		return (0);
	if (k < 3 && stat == 1)
		return (0);
	if (k == 4 && stat == 1)
		return (1);
	if (k == 6 && stat == 1)
		return (-1);
	return (0);
}
