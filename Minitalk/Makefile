# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 08:22:55 by hgoorick          #+#    #+#              #
#    Updated: 2021/09/28 09:40:52 by hgoorick         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **** #
# NAME #
# **** #

NAMES		=	serveur
NAMEC		=	client

# *** #
# DIR #
# *** #

DIRSRC		= ./srcs/
DIRINC		= ./includes

# ******* #
# FILES c #
# ******* #

SRCA		=	${DIRSRC}all.c
SRCS		=	${DIRSRC}serveur.c
SRCC		=	${DIRSRC}client.c

# ******* #
# FILES o #
# ******* #

OBJA		=	${SRCA:.c=.o}
OBJS		=	${SRCS:.c=.o}
OBJC		=	${SRCC:.c=.o}

# ############## #
# FLAGS COMMANDS #
# ############## #

CFLAGS		=	-Wall -Wextra -Werror

# ######## #
# COMMANDS #
# ######## #

.c.o:
				@gcc ${CFLAGS} -I ${DIRINC} -c $< -o ${<:.c=.o}

all: 		${NAMES} ${NAMEC}
				@printf "\e[32;3mAll successfully build\e[0m\n"

${NAMES}:	${OBJA} ${OBJS}
				@gcc ${CFLAGS} ${OBJA} ${OBJS} -o ${NAMES}
				@printf "\e[32;3m$@ successfully build\e[0m\n"

${NAMEC}:	${OBJA} ${OBJC}
				@gcc ${CFLAGS} ${OBJA} ${OBJC} -o ${NAMEC}
				@printf "\e[32;3m$@ successfully build\e[0m\n"

clean:
				@rm -f ${OBJS} ${OBJC} ${OBJA}
				@printf "\e[31;3mClean files\e[0m\n"

fclean: 	clean
				@rm -f serveur client
				@printf "\e[31;3mClean exec\e[0m\n"

re: 		fclean all
