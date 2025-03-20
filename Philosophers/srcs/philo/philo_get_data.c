/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_get_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:26:22 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:26:25 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_get_data(t_philo_data *d, int i)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	if (!node)
		return (aristote_is_dead(NULL, NULL, THREAD_FAILED));
	node->id = i + 1;
	node->thread_id = 0;
	pthread_mutex_init(&node->fork_lock, NULL);
	pthread_mutex_init(&node->last_meal_lock, NULL);
	node->data = d;
	node->last_meal = 0;
	return (node);
}
