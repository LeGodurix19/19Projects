/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:24:59 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:25:04 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	it_s_time_to_sleep(useconds_t usec)
{
	useconds_t		before;
	useconds_t		after;

	before = give_me_the_time();
	after = before;
	while (after - before < usec)
	{
		if (usleep(usec) == -1)
			return (-1);
		after = give_me_the_time();
	}
	return (0);
}
