/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:48:58 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/21 10:49:01 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_write_str(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write (1, str, ft_strlen(str));
	return (ft_strlen(str));
}
