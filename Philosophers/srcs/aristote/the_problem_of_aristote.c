/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_perror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:27:22 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:27:25 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	the_problem_of_aristote(char *param, int err_code)
{
	ft_putstr_fd("philo: ", 2);
	if (err_code == INV_ARGS)
		ft_putstr_fd(INV_NB_ARG, 2);
	if (err_code == NO_MEMORY)
		ft_putstr_fd(NO_MEMORY_LEFT, 2);
	if (err_code == THREAD_FAILED)
		ft_putstr_fd(CREATE_THREAD_FAILED, 2);
	if (err_code == INV_PHILO_COUNT)
		ft_putstr_fd(INV_NB_PHILO, 2);
	if (err_code == INV_DIE_TIME)
		ft_putstr_fd(INV_DEAD_TIME, 2);
	if (err_code == INV_EAT_TIME)
		ft_putstr_fd(INV_TIME_TO_EAT, 2);
	if (err_code == INV_SLEEP_TIME)
		ft_putstr_fd(INV_TIME_TO_SLEEP, 2);
	if (err_code == INV_REPEAT_COUNT)
		ft_putstr_fd(INV_MUST_EAT, 2);
	if (err_code == TOO_MANY_PHILO)
		ft_putstr_fd(TOO_MANY_PHILO_TXT, 2);
	if (param && err_code != INV_ARGS && err_code != NO_MEMORY
		&& err_code != THREAD_FAILED)
		ft_putstr_fd(param, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}
