# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 11:22:22 by hugoorickx        #+#    #+#              #
#    Updated: 2022/03/30 11:22:22 by hugoorickx       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../datas_makefile/colors.mk
-include ../datas_makefile/libft_datas.mk

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# ######## #
# COMMANDS #
# ######## #

${OBJ_DIR}/%.o:${SRC_DIR}/%.c
				@${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@
				@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}\t\t[${GREEN}%-30s${DEFAULT}]" "Libft" $<
				@sleep ${FAST}

all: 		 build_dir ${NAME}

${NAME}: 	 ${OBJS}
				@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]%40s\n" "Compile" ""
				@ar rc ${NAME} ${OBJS}
				@ranlib ${NAME}
				@mkdir -p bin
				@mv libft.a ./bin/

build_dir:
		@mkdir -p ${OBJ_DIR}

clean:
				@rm -rf ${OBJ_DIR}
				@printf "${START_FIRST}${RED}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]\n" "Cleaning up object files"

fclean: 	clean
				@rm -f ./bin/${NAME}
				@printf "${START_FIRST}${RED}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]\n" "Removed ${NAME}"

re: 		fclean all

add:
			@bash add.sh
			@printf "${GREEN}File(s) ok !${DEFAULT}\n"