/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:27:50 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:27:52 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :  															*/
/*			It converts the string argument str to an integer.				*/
/*																			*/
/*	Argument :																*/
/*			This is the string representation of an integral number.		*/
/*																			*/
/*	Return :																*/
/*			This function returns the converted integral number as 			*/
/*				an int value.												*/
/*			If no valid conversion could be performed, it returns zero.		*/
/* ************************************************************************ */

#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned int	rep;
	int				i;

	rep = 0;
	i = -1;
	if (str[i] == '+' )
			i++;
	while (str[++i] >= '0' && str[i] <= '9')
	{
		if ((rep * 10) + (str[i] - 48) > INT_MAX)
			return (-1);
		rep = (rep * 10) + (str[i] - 48);
	}
	return (rep);
}
