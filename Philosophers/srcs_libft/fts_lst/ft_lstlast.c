/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:29:35 by hgoorick          #+#    #+#             */
/*   Updated: 2021/11/25 17:29:37 by hgoorick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************ */
/*	Description :															*/
/*			Returns the last item in the list.								*/
/*																			*/
/*	Argument :																*/
/*			lst		=>		The beginning of the list.						*/
/*																			*/
/*	Return :																*/
/*			Last item in the list											*/
/* ************************************************************************ */

#include "philo.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
