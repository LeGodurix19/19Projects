/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:25:46 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:25:49 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_thread(void *node)
{
	t_philo		*philo;
	t_philo		*next;
	int			i;

	i = -1;
	philo = ((struct s_list *)node)->content;
	next = ((struct s_list *)node)->next->content;
	it_s_time_to_sleep(!(philo->id % 2) * 3);
	pthread_mutex_lock(&philo->data->died_lock);
	while (philo->id != next->id && !philo->data->died
		&& (philo->data->repeat_count == -2 || ++i < philo->data->repeat_count))
	{
		pthread_mutex_unlock(&philo->data->died_lock);
		philo_actions(node, philo, next);
		pthread_mutex_lock(&philo->data->died_lock);
	}
	pthread_mutex_unlock(&philo->data->died_lock);
	return (NULL);
}
