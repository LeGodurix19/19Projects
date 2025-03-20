/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_timestamp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:27:35 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:27:38 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	show_me_what_you_do(t_list *philos, char *action, useconds_t t)
{
	useconds_t	time;
	t_philo		*philo;
	int			died;
	int			eat_count;

	philo = philos->content;
	pthread_mutex_lock(&philo->data->died_lock);
	died = philo->data->died;
	pthread_mutex_lock(&philo->data->eat_count_lock);
	eat_count = philo->data->eat_count;
	time = give_me_the_time() - philo->data->init_time;
	if (philo->data->repeat_count * philo->data->philo_count != eat_count
		&& (!died || action[0] == 'd'))
		printf("[%06d]  %03d  %s\n", time, philo->id, action);
	if (action[5] == 'e')
		philo->data->eat_count++;
	pthread_mutex_unlock(&philo->data->eat_count_lock);
	pthread_mutex_unlock(&philo->data->died_lock);
	if (philo->data->repeat_count * philo->data->philo_count != eat_count
		&& (!died || action[0] == 'd'))
		it_s_time_to_sleep(t);
}
