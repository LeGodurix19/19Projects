/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:29:14 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:30:55 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Removes and frees the memory of the element passed in parameter	*/
/*				and all the following elements, to using del and free		*/
/*				Finally, the initial pointer must be set to NULL.			*/
/*																			*/
/*	Argument :																*/
/*			lst		=>		The address of the pointer to an item.			*/
/*			del		=>		The address of the function allowing delete 	*/
/*								the content of an item.						*/
/*																			*/
/*	Return :																*/
/*			None.															*/
/* ************************************************************************ */

#include "philo.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tl1;
	t_list	*tl2;

	tl1 = *lst;
	while (tl1)
	{
		tl2 = tl1->next;
		free(tl1->content);
		free(tl1);
		tl1 = tl2;
	}
	*lst = NULL;
}
