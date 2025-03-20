/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:26:59 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:27:02 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*philo_lst(t_philo_data *d)
{
	int		i;
	t_list	*philos;

	i = -1;
	philos = NULL;
	while (++i < d->philo_count)
		ft_lstadd_back(&philos, ft_lstnew(philo_get_data(d, i)));
	return (philos);
}
