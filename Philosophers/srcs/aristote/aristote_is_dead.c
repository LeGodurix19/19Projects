/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:26:11 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:26:12 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*aristote_is_dead(t_list *philos, char *param, int err_code)
{
	t_philo	*philo;
	t_list	*temp;

	temp = philos;
	if (err_code != END)
		the_problem_of_aristote(param, err_code);
	while (philos)
	{
		philo = philos->content;
		if (philo->id == philo->data->philo_count)
			philos->next = NULL;
		philos = philos->next;
	}
	ft_lstclear(&temp);
	return (NULL);
}
