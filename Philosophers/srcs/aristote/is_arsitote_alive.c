/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:27:11 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:27:14 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*is_arsitote_alive(t_list *start, t_philo *philo)
{
	long	eat_c;
	long	last_meal;

	while (1)
	{
		philo = start->content;
		pthread_mutex_lock(&philo->data->eat_count_lock);
		eat_c = philo->data->eat_count;
		pthread_mutex_unlock(&philo->data->eat_count_lock);
		pthread_mutex_lock(&philo->last_meal_lock);
		last_meal = philo->last_meal;
		pthread_mutex_unlock(&philo->last_meal_lock);
		if (give_me_the_time() - philo->data->init_time - last_meal >= \
			philo->data->die_time || eat_c == \
			philo->data->philo_count * philo->data->repeat_count)
		{
			pthread_mutex_lock(&philo->data->died_lock);
			philo->data->died = 1;
			pthread_mutex_unlock(&philo->data->died_lock);
			if (eat_c != philo->data->philo_count * philo->data->repeat_count)
				show_me_what_you_do(start, PHILO_DIE, 0);
			return (NULL);
		}
		start = start->next;
	}
}
