/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adds_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:47:45 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/21 10:47:56 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	zero(void)
{
	write(1, "0", 1);
	return (1);
}

int	ft_int_len(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		i++;
	while (nbr / 10 != 0 && i++ < 10)
		nbr /= 10;
	return (i);
}

int	ft_uint_len(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr / 10 != 0 && i++ < 10)
		nbr /= 10;
	return (i);
}

int	ft_hex_len(unsigned int nbr)
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
