/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:28:09 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:28:11 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			The function computes the length of the string str up to, but 	*/
/*				not including the terminating null character.				*/
/*																			*/
/*	Argument :																*/
/*			str		=>	This is the string whose length is to be found.		*/
/*																			*/
/*	Return :																*/
/*			This function returns the length of string.						*/
/* ************************************************************************ */

#include "philo.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
