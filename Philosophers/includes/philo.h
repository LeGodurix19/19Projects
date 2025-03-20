/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:32:50 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:33:37 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "struct.h"
# include "define.h"

t_philo_data	convert_datas(char **argv);

useconds_t		give_me_the_time(void);

t_philo			*philo_get_data(t_philo_data *d, int i);

t_list			*philo_lst(t_philo_data *d);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);

void			*aristote_is_dead(t_list *philos, char *param, int err_code);
void			*aristote_is_born(int philo_count, t_list *philos);
void			*start_thread(void *node);
void			*is_arsitote_alive(t_list *start, t_philo *philo);
void			philo_actions(t_list *node, t_philo *philo, t_philo *next);
void			show_me_what_you_do(t_list *philos, char *action, useconds_t t);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst);

int				the_problem_of_aristote(char *param, int err_code);
int				it_s_time_to_sleep(useconds_t usec);
int				ft_strlen(const char *s);
int				ft_nbrlen(long n, int base);
int				ft_atoi(const char *str);
int				ft_putstr_fd(char *s, int fd);
int				ft_putchar_fd(char c, int fd);
int				ft_putnchar_fd(char c, int fd, int n);
int				ft_putnbr_fd(long unsigned n, int fd);

#endif
