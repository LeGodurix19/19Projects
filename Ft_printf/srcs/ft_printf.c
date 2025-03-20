/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:48:08 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/21 10:48:10 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_var(va_list all, const char input)
{
	if (input == 'd' || input == 'i')
		return (ft_write_int(va_arg(all, int)));
	else if (input == 'c')
		return (ft_write_char(va_arg(all, int)));
	else if (input == 's')
		return (ft_write_str(va_arg(all, char *)));
	else if (input == 'p')
		return (ft_write_ptr(va_arg(all, void *)));
	else if (input == 'u')
		return (ft_write_uint(va_arg(all, int)));
	else if (input == 'x')
		return (ft_write_hex(va_arg(all, int), "0123456789abcdef"));
	else if (input == 'X')
		return (ft_write_hex(va_arg(all, int), "0123456789ABCDEF"));
	else if (input == '%')
		return (ft_write_char('%'));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	all;
	int		long1;
	int		long2;
	int		long3;
	int		nbElem;

	long1 = -1;
	long2 = 0;
	long3 = 1;
	nbElem = 0;
	va_start(all, input);
	while ((input[++long1] || long3) && ((int)ft_strlen(input) >= (long1 + 1)))
	{
		if (input[long1] == '%')
		{
			long3 = ft_var(all, input[++long1]);
			long2 += long3;
		}
		else
		{
			write(1, &input[long1], 1);
			nbElem++;
		}
	}
	return (long2 + nbElem);
}
/*
int main(void)
{
    int x = ft_printf("%d", 10);
    printf("\nLongueur ft_printf  : %d\n", x);
    x = printf("%d", 10);
    printf("\nLongueur printf    : %d\n", x);
}
*/
