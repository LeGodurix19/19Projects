# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugogoorickx <hugogoorickx@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 11:47:38 by hugoorickx        #+#    #+#              #
#    Updated: 2022/04/15 13:05:20 by hgoorick         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include datas_makefile/colors.mk
-include datas_makefile/srcs.mk

CFLAGS		=	-Wall -Wextra -Werror

NB = cub3D_bonus

all:  global_libft_init creat_dir print ${NAME}

-include datas_makefile/manip_global_lib.mk

#Mac_OS
#-lmlx -framework OpenGL -framework AppKit -lz
#Mac Hugo
#-I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

${NAME}:	${OBJS} ${OBJS_MAIN}
	@gcc ${CFLAGS} -I ${INCLUDES} -lmlx -framework OpenGL -framework AppKit -lz ${LIBFT} ${OBJS} ${OBJS_MAIN} -o $@
	@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]%40s\n" "Compile" ""

${OBJ_DIR}/%.o:${SRC_DIR}/%.c
	@${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@
	@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}\t\t[${GREEN}%-30s${DEFAULT}]" "cub3D" $<
	@sleep ${FAST}

bonus:		global_libft_init creat_dir print ${NB}

${NB}:		${OBJS} ${OBJS_BONUS}
	@gcc ${CFLAGS} -I ${INCLUDES} -lmlx -framework OpenGL -framework AppKit -lz ${LIBFT} ${OBJS} ${OBJS_BONUS} -o ${NB}
	@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]%40s\n" "Compile" ""




creat_dir:
	@mkdir -p ${OBJ_DIR}

clean:
	@rm -rf ${OBJ_DIR}
	@printf "${RED}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]\n" "Cleaning up object files"

fclean: clean
	@rm -f ${NB} ${NAME}
	@printf "${RED}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]\n" "Removed ${NAME}"

re: re_libft print fclean  all

run: ${NAME}
	@./${NAME}

fclean_all: fclean fclean_libft

print:
	@printf "\n\t${BLUE_UNDERLINE}${NAME} :${DEFAULT}\n\n"

add:
	@bash ./bash/add.sh
	@printf "${GREEN}File(s) ok !${DEFAULT}\n\n"

man:
	@bash ./bash/makefile_man.sh

.PHONY:
	all bonus creat_dir clean fclean re fclean_all print add man
