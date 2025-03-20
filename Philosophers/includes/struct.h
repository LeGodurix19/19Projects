/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:32:19 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:32:20 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_philo_data
{
	int				philo_count;
	useconds_t		init_time;
	long			repeat_count;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	long			eat_count;
	pthread_mutex_t	eat_count_lock;
	int				died;
	pthread_mutex_t	died_lock;
}					t_philo_data;

typedef struct s_philo
{
	int					id;
	pthread_t			thread_id;
	pthread_mutex_t		fork_lock;
	useconds_t			last_meal;
	pthread_mutex_t		last_meal_lock;
	struct s_philo_data	*data;
}						t_philo;

#endif
