/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:34:20 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/10 23:42:08 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define ERROR_WRONG_VALUE "Error\n Wrong value\n"
# define ERROR_MALLOC "Error\n Malloc doesn't work\n"
# define ERROR_NOT_MAP "Error\n Not map in file\n"
# define ERROR_WRONG_CHAR "Error\n Wrong char in map\n"
# define ERROR_WRONG_POS "Error\n Wrong position of char in map\n"
# define ERROR_RBG_MAX_INT "Error\n rgb can't be bigger than max int\n"
# define ERROR_RBG_NEG "Error\n rgb can't be negative\n"
# define ERROR_RGB_255 "Error\n rgb can't be bigger than 255\n"
# define ERROR_RGB_MIN_INT "Error\n rgb can't be smaller than min int\n"
# define ERROR_MORE_PLAYER "Error\n Two players or more in map\n"
# define ERROR_NO_PLAYER "Error\n No player in map\n"
# define ERROR_VOID_LINE "Error\n Void line in map\n"
# define ERROR_MORE_COLOR "Error\n Two colors for the floor/sky\n"
# define ERROR_INV_NUMBER_COLOR "Error\n Invalid number of colors for the rgb\n"
# define ERROR_NB_ARGUMENTS "Error\n Arguments\n./cub3D <path_to_file.cub>\n"
# define ERROR_WRONG_FILENAME "Error\n File name\n./cub3D <path_to_file.cub>\n"
# define ERROR_FILE_NOT_EXIST "Error\n File doesn't exist\n"
# define ERROR_DATA_MISSING "Error\n Datas missing\n"
# define ERROR_TOO_MANY_DATAS "Error\n too many datas\n"
# define ERROR_DATA_INV "Error\n Data not valid\n"
# define ERROR_TOO_MANY_IMG "Error\n Two images for a wall\n"
# define ERROR_WRONG_TYPE_IMG "Error\n Wrong type for image\n"
# define ERROR_IMG_NOT_EXIST "Error\n image doesn't exist\n"
# define MESSAGE_END_EXIT "Thanks for playing\n"

# define W 13
# define Q 12
# define ESC 53
# define D 2
# define A 0
# define S 1
# define WINDOW_PRESS_EXIT 17
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

# define SCREEN_WIGHT 1000
# define SCREEN_HEIGHT 500

# define PI 3.14159265359

#endif
