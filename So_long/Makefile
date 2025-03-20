NAME		=	so_long

# *** #
# DIR #
# *** #

DIRSRC		= ./srcs/
DIRINC		= ./includes/

# ******* #
# FILES c #
# ******* #

SRC			=	${DIRSRC}ft_free_all.c \
				${DIRSRC}ft_move_3.c \
				${DIRSRC}ft_move_2.c \
				${DIRSRC}ft_move_1.c \
				${DIRSRC}print_in_map_1.c \
				${DIRSRC}print_in_map_2.c \
				${DIRSRC}ft_adds.c \
				${DIRSRC}game.c \
				${DIRSRC}exec_mlx.c \
				${DIRSRC}gnl_1.c \
				${DIRSRC}gnl_2.c \
				${DIRSRC}ft_checks.c \
				${DIRSRC}ft_all_check.c \
				${DIRSRC}put.c \
				${DIRSRC}parsing.c \
				${DIRSRC}transfert_data.c \
				${DIRSRC}main.c

# ******* #
# FILES o #
# ******* #

OBJ			=	${SRC:.c=.o}

# ############## #
# FLAGS COMMANDS #
# ############## #

CFLAGS		=	-Wall -Wextra -Werror
MLX			=	-lmlx -framework OpenGL -framework AppKit -lz

# ######## #
# COMMANDS #
# ######## #

.c.o:
				@gcc ${CFLAGS} -I ${DIRINC} -Imlx -c $< -o ${<:.c=.o}
				@printf "\e[32;3m.\e[0m"

all: 		${NAME}

${NAME}:	${OBJ}
				@gcc ${CFLAGS} ${MLX} ${OBJ} -o ${NAME}
				@printf "\n\e[32;3m$@ successfully build\e[0m\n"

clean:
				@rm -f ${OBJ}
				@printf "\e[31;3mClean files\e[0m\n"

fclean: 	clean
				@rm -f ${NAME}
				@printf "\e[31;3mClean exec\e[0m\n"

re: 		fclean all
