/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:33:02 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:33:04 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define PHILO_EAT "is eating"
# define PHILO_SLEEP "is sleeping"
# define PHILO_THINK "is thinking"
# define PHILO_TAKE_FORK "has taken a fork"
# define PHILO_DIE "died"

# define INV_NB_ARG "invalid number of arguments"
# define NO_MEMORY_LEFT "no memory left on device"
# define CREATE_THREAD_FAILED "failed to create a thread"
# define INV_NB_PHILO "invalid philosopher_count: "
# define INV_DEAD_TIME "invalid time_to_die: "
# define INV_TIME_TO_EAT "invalid time_to_eat: "
# define INV_TIME_TO_SLEEP "invalid time_to_sleep: "
# define INV_MUST_EAT "invalid must_eat: "
# define TOO_MANY_PHILO_TXT "too many threads: "

# define END 1
# define INV_ARGS -1
# define TOO_MANY_PHILO -2
# define INV_PHILO_COUNT -3
# define INV_DIE_TIME -4
# define INV_EAT_TIME -5
# define INV_SLEEP_TIME -6
# define INV_REPEAT_COUNT -7
# define NO_MEMORY -8
# define THREAD_FAILED -9

#endif
