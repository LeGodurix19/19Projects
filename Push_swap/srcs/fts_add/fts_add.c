/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:09:44 by hgoorick          #+#    #+#             */
/*   Updated: 2021/10/28 14:09:46 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/****************************/
/* Return len of the string */
/****************************/

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/************************/
/* Write error and exit */
/************************/

void	error(void)
{
	write(1, "Error\n", 6);
	exit(-1);
}

/***********************/
/* Convert char to int */
/***********************/

int	ft_atoi(const char *str)
{
	long long		rst;
	int				sign;

	rst = 0;
	sign = 0;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rst = rst * 10 + (*str - '0');
		str++;
	}
	if ((rst > INT_MAX && !sign) || (rst - 1 > INT_MAX && sign))
		error();
	if (sign)
		return (-rst);
	return (rst);
}

/********************/
/* Compare 2 string */
/********************/

int	ft_strcmp(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (i == len - 1);
}

/************************/
/* return 1 if is digit */
/************************/

int	is_digit(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == '-')
		idx++;
	idx--;
	while (str[++idx])
		if ('0' > str[idx] || '9' < str[idx])
			return (0);
	return (1);
}
