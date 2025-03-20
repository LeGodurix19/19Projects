# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 16:00:11 by hgoorick          #+#    #+#              #
#    Updated: 2021/09/06 14:01:48 by hgoorick         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** #
# LIBFT #
# ***** #

NAME			= 	libft.a

# ****** #
# PART 1 #
# ****** #

SRC1		=	ft_isalpha.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_strdup.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_memmove.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strrchr.c \
				ft_strchr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_strncmp.c

OBJS1		=	${SRC1:.c=.o}

# ****** #
# PART 2 #
# ****** #

SRC2		=	ft_putchar_fd.c \
				ft_striteri.c \
				ft_itoa.c \
				ft_putendl_fd.c \
				ft_strjoin.c \
				ft_putnbr_fd.c \
				ft_strtrim.c \
				ft_putstr_fd.c \
				ft_substr.c \
				ft_split.c \
				ft_strmapi.c

OBJS2		=	${SRC2:.c=.o}

# ########## #
# PART BONUS #
# ########## #

SRCBONUS	=	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstnew.c \
				ft_lstmap.c \
				ft_lstsize.c

OBJSBONUS	= 	${SRCBONUS:.c=.o}

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# ######## #
# COMMANDS #
# ######## #

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: 		${NAME}

${NAME}: 	${OBJS1} ${OBJS2}
				ar rc ${NAME} ${OBJS1} ${OBJS2}
				ranlib ${NAME}

bonus:		${OBJS1} ${OBJS2} ${OBJSBONUS}
				ar rc ${NAME} ${OBJS1} ${OBJS2} ${OBJSBONUS}
				ranlib ${NAME}

clean:
				rm -f ${OBJS1} ${OBJS2} ${OBJSBONUS}

fclean: 	clean
				rm -f ${NAME}

re: 		fclean all
