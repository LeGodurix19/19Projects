/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:29:03 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:29:04 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Adds the new element to the end of the list.					*/
/*																			*/
/*	Argument :																*/
/*			alst	=>	The address of the pointer to the first element 	*/
/*							from the list.									*/
/*			new		=>	The address of the pointer to the element to add 	*/
/*							to the list.									*/
/*																			*/
/*	Return :																*/
/*			None.															*/
/* ************************************************************************ */

#include "philo.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*t;

	if (*alst)
	{
		t = ft_lstlast(*alst);
		t->next = new;
	}
	else
		*alst = new;
}
