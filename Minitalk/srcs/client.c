/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 07:42:47 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/28 09:38:55 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

int	send_ascii(pid_t pid, int c)
{
	int	bit;

	bit = NB_BITS;
	while (--bit > -1)
	{
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR1) == -1)
				return (1);
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				return (1);
		usleep(TIME_TO_SLEEP);
	}
	return (0);
}

int	ft_send_message(pid_t pid, char *message)
{
	int	i;

	i = -1;
	while (message[++i])
		if (send_ascii(pid, message[i]))
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (ft_putstr(ORDER));
	pid = ft_atoi(argv[1]);
	if (pid > 0 && pid <= 4194304)
	{
		if (ft_send_message(pid, argv[2]))
			return (ft_putstr(ERROR_SEND));
	}
	else
		return (ft_putstr(WRONG_PID));
	return (0);
}
