/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:35:04 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/28 09:37:20 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	write (1, str, ft_strlen(str));
	return (0);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int	ft_atoi(const char *str)
{
	long	i;
	long	rtn;
	char	is_neg;

	i = 0;
	rtn = 0;
	is_neg = '+';
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = str[i++];
	if (str[i] == '+' && is_neg == '-')
		return (0);
	i += (str[i] == '+');
	while (str[i] >= '0' && str[i] <= '9')
	{
		rtn *= 10;
		rtn += str[i] - '0';
		i++;
	}
	if (rtn < 0)
		return ((is_neg != '-') * -1);
	if (is_neg == '-')
		rtn *= -1;
	return (rtn);
}
