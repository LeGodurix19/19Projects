# ***** #
# LIBFT #
# ***** #

NAME		= 	libftprintf.a

# *** #
# DIR #
# *** #

INC			= 	./includes/

SOURCEDIR 	=	./srcs/

# ***** #
# FILES	#
# ***** #

SRC			=	${SOURCEDIR}ft_write_hex.c \
				${SOURCEDIR}ft_write_int.c \
				${SOURCEDIR}ft_write_ptr.c \
				${SOURCEDIR}ft_write_str.c \
				${SOURCEDIR}ft_write_uint.c \
				${SOURCEDIR}ft_write_char.c \
				${SOURCEDIR}ft_adds_ft.c \
				${SOURCEDIR}ft_printf.c

OBJS		=	${SRC:.c=.o}

# ############## #
# COMMANDS PARAM #
# ############## #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# ######## #
# COMMANDS #
# ######## #

.c.o:
				${CC} ${CFLAGS} -I ${INC} -c $< -o ${<:.c=.o}

all: 		${NAME}
				ar -rc $(NAME) $(OBJS)

${NAME}: 	${OBJS}

clean:
				rm -f ${OBJS}

fclean: 	clean
				rm -f ${NAME}

re: 		fclean all
