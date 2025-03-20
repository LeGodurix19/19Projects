# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_datas.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 13:02:55 by hugoorickx        #+#    #+#              #
#    Updated: 2022/04/08 13:02:55 by hugoorickx       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** #
# LIBFT #
# ***** #

NAME			= 	libft.a

# *** #
# INC #
# *** #

INCLUDES	=	../includes/

# *** #
# DIR #
# *** #

OBJ_DIR		=	./objs
SRC_DIR		=	./srcs

# *** #
# OBJ #
# *** #

OBJS	= 	$(addprefix ${OBJ_DIR}/,${SRC:.c=.o})

# *** #
# SRC #
# *** #

SRC += ft_all_space.c
SRC += ft_atoi.c
SRC += ft_free_mat.c
SRC += ft_isdigit.c
SRC += ft_isspace.c
SRC += ft_matrixlcopy.c
SRC += ft_matrixlen.c
SRC += ft_split_up.c
SRC += ft_split.c
SRC += ft_strcmp.c
SRC += ft_strlcpy.c
SRC += ft_strlen.c
SRC += gnl.c
