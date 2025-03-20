/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:35:35 by hgoorick          #+#    #+#             */
/*   Updated: 2021/09/28 09:36:46 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************************************/
/* NB_BITS          => to read Unicode                      */
/* TIME_TO_SLEEP    => microsecond between 2 sending bit    */
/* STR_SERV         => txt waiting  clients                 */
/* ORDER            => when error in clients' parametres    */
/* WRONG_PID        => when the pid is an error             */
/* ERROR_SEND       => when error during sending            */
/* ERROR_RECEPT     => when error during receiving          */
/************************************************************/

#ifndef ALL_H
# define ALL_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>

# define ERROR_RECEPT "Error in reception\n"
# define ERROR_SEND "Error during sending\n"
# define WRONG_PID "Wrong PID\n"
# define ORDER "Enter : ./client <PID Server> Message"
# define STR_SERV "\nSentences transmitted :\n"
# define NB_BITS 16
# define TIME_TO_SLEEP 250

void	ft_putchar(int c);

void	ft_putnbr(int n);

int		ft_putstr(char *str);

int		ft_atoi(const char *str);

#endif
