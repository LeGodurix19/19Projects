/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:26:00 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:26:02 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_actions(t_list *node, t_philo *philo, t_philo *next)
{
	pthread_mutex_lock(&philo->fork_lock);
	show_me_what_you_do(node, PHILO_TAKE_FORK, 0);
	pthread_mutex_lock(&next->fork_lock);
	show_me_what_you_do(node, PHILO_TAKE_FORK, 0);
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = give_me_the_time() - philo->data->init_time;
	pthread_mutex_unlock(&philo->last_meal_lock);
	show_me_what_you_do(node, PHILO_EAT, philo->data->eat_time);
	show_me_what_you_do(node, PHILO_SLEEP, 0);
	pthread_mutex_unlock(&next->fork_lock);
	pthread_mutex_unlock(&philo->fork_lock);
	it_s_time_to_sleep(philo->data->sleep_time);
	show_me_what_you_do(node, PHILO_THINK, 0);
}
