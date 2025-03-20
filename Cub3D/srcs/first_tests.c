/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:21:57 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/08 13:49:09 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	first_tests(char **argv, int nb_arg)
{
	int		fd;
	char	*file;

	if (nb_arg != 2)
		ft_print_error(ERROR_NB_ARGUMENTS, NULL);
	file = argv[1];
	if (ft_strlen(file) < 6 || file[ft_strlen(file) - 1] != 'b'
		|| file[ft_strlen(file) - 2] != 'u' || file[ft_strlen(file) - 3] != 'c'
		|| file[ft_strlen(file) - 4] != '.')
		ft_print_error(ERROR_WRONG_FILENAME, NULL);
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_print_error(ERROR_FILE_NOT_EXIST, NULL);
	return (fd);
}
