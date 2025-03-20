/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:25:11 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:25:16 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_data	d;
	t_list			*philos;

	if (argc != 5 && argc != 6)
	{
		aristote_is_dead(NULL, NULL, INV_ARGS);
		printf("usage: philo <philo_count> <die_time>");
		printf(" <eat_time> <sleep_time> [<must_eat>]\n");
		return (1);
	}
	d = convert_datas(argv);
	if (d.philo_count <= 0 || d.philo_count > 800 || d.die_time == -1
		|| d.eat_time == -1 || d.sleep_time == -1 || d.repeat_count == -1
		|| !d.repeat_count)
		return (1);
	d.init_time = give_me_the_time();
	d.died = 0;
	d.eat_count = 0;
	pthread_mutex_init(&d.died_lock, NULL);
	pthread_mutex_init(&d.eat_count_lock, NULL);
	philos = philo_lst(&d);
	ft_lstlast(philos)->next = philos;
	aristote_is_born(d.philo_count, philos);
	aristote_is_dead(philos, NULL, END);
	return (0);
}
