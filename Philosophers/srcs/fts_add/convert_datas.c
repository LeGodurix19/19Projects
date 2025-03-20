/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:25:25 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:25:26 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo_data	convert_datas(char **argv)
{
	t_philo_data	d;

	d.philo_count = ft_atoi(argv[1]);
	if (d.philo_count <= 0)
		aristote_is_dead(NULL, argv[1], INV_PHILO_COUNT);
	if (d.philo_count > 200)
		aristote_is_dead(NULL, argv[1], TOO_MANY_PHILO);
	d.die_time = ft_atoi(argv[2]);
	if (d.die_time == -1)
		aristote_is_dead(NULL, argv[2], INV_DIE_TIME);
	d.eat_time = ft_atoi(argv[3]);
	if (d.eat_time == -1)
		aristote_is_dead(NULL, argv[3], INV_EAT_TIME);
	d.sleep_time = ft_atoi(argv[4]);
	if (d.sleep_time == -1)
		aristote_is_dead(NULL, argv[4], INV_SLEEP_TIME);
	d.repeat_count = -2;
	if (argv[5])
	{
		d.repeat_count = ft_atoi(argv[5]);
		if (d.repeat_count == -1 || !d.repeat_count)
			aristote_is_dead(NULL, argv[5], INV_REPEAT_COUNT);
	}
	return (d);
}
