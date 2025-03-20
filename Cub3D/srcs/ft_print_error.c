/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:21:54 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/03/30 11:21:54 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	ft_print_error(char *output, t_datas_global *all_datas)
{
	free_all(all_datas);
	write(2, output, ft_strlen(output));
	exit (1);
}
