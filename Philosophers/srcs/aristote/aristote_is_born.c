/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:26:46 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:26:51 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*aristote_is_born(int philo_count, t_list *philos)
{
	int		i;
	t_list	*start;
	t_philo	*philo;

	i = -1;
	start = philos;
	while (++i < philo_count)
	{
		philo = start->content;
		if (pthread_create(&philo->thread_id, NULL, start_thread, start))
			return (aristote_is_dead(philos, NULL, THREAD_FAILED));
		start = start->next;
	}
	is_arsitote_alive(start, NULL);
	i = -1;
	while (++i < philo_count)
	{
		philo = start->content;
		pthread_join(philo->thread_id, NULL);
		start = start->next;
	}
	return (NULL);
}
