/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 07:42:32 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/28 09:39:19 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void	ft_convert(int signum)
{
	static int	c;
	static int	bit;
	static char	status;

	if (status != 1)
	{
		bit = NB_BITS;
		c = 0;
		status = 1;
	}
	if (--bit > -1)
	{
		if (signum == SIGUSR1)
			c |= (1 << bit);
		if (!bit)
		{
			ft_putchar(c);
			status = 0;
		}
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("PID : ");
	ft_putnbr(pid);
	ft_putstr(STR_SERV);
	while (1)
	{
		if (signal(SIGUSR1, ft_convert) == SIG_ERR)
			ft_putstr(ERROR_RECEPT);
		if (signal(SIGUSR2, ft_convert) == SIG_ERR)
			ft_putstr(ERROR_RECEPT);
	}
}
