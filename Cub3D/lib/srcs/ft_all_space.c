/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:22:29 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/03/30 11:30:04 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	ft_all_space(char *input)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(input))
		if (!ft_isspace(input[i]))
			return (1);
	return (0);
}
