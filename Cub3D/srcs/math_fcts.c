/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:04:39 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/08 13:04:17 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

double	wd(int val1, double val2, double val3, double val4)
{
	return (fabs((val1 - val2 + (1 - val3) / 2) / val4));
}

double	ray(t_datas_player *data, int statut, double cam_x)
{
	if (statut)
		return (data->dir_x + (data->plane_x * cam_x));
	else
		return (data->dir_y + (data->plane_y * cam_x));
}

double	delta(double val1, double val2)
{
	return (sqrtf(1 + (val1 * val1) / (val2 * val2)));
}

double	dpx(t_datas_player *val1, double val2, int val3)
{
	if (val3)
		return (val1->dir_x * cos(-val2) - val1->dir_y * sin(-val2));
	else
		return (val1->plane_x * cos(-val2) - val1->plane_y * sin(-val2));
}

double	dpy(t_datas_player *val1, double val2, int val3, double val4)
{
	if (val3)
		return (val4 * sin(-val2) + val1->dir_y * cos(-val2));
	else
		return (val4 * sin(-val2) + val1->plane_y * cos(-val2));
}
