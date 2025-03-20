# *************** #
# COLORS & PARAMS #
# *************** #

DEFAULT		=	\033[0;39m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m

NB_CHAR		=	40

# **** #
# NAME #
# **** #

NAME		=	philo

# *** #
# DIR #
# *** #

SRC_DIR		=	./srcs
SRC_LFT_DIR	=	./srcs_libft

PHILO		=	philo/
ARIST		=	aristote/
FTS_ADD		=	fts_add/
FT_PUT		=	ft_put/
FTS_LST		=	fts_lst/

OBJ_DIR		=	./objs
OBJ_LFT_DIR	=	./objs_libft

INCLUDES	=	./includes


# ******* #
# FILES c #
# ******* #

SRC_LFT_PUT	=	ft_putchar_fd.c \
				ft_putnbr_fd.c \
				ft_putnchar_fd.c \
				ft_putstr_fd.c

SRC_LFT_LST	=	ft_lstadd_back.c \
				ft_lstclear.c \
				ft_lstlast.c \
				ft_lstnew.c


SRC_LFT		=	$(addprefix ${FT_PUT}, ${SRC_LFT_PUT:.c=.o}) \
				$(addprefix ${FTS_LST}, ${SRC_LFT_LST:.c=.o}) \
				ft_atoi.c \
				ft_nbrlen.c \
				ft_strlen.c

SRC_ARIST	=	aristote_is_born.c \
				aristote_is_dead.c \
				is_arsitote_alive.c \
				the_problem_of_aristote.c

SRC_PHILO	=	philo_actions.c \
				philo_lst.c \
				philo_get_data.c


SRC_FTS_ADD	=	give_me_the_time.c \
				convert_datas.c \
				start_thread.c \
				it_s_time_to_sleep.c \
				show_me_what_you_do.c

SRC			=	$(addprefix ${PHILO}, ${SRC_PHILO:.c=.o}) \
				$(addprefix ${ARIST}, ${SRC_ARIST:.c=.o}) \
				$(addprefix ${FTS_ADD}, ${SRC_FTS_ADD:.c=.o}) \
				main.c

# ******* #
# FILES o #
# ******* #

OBJ			=	$(addprefix ${OBJ_DIR}/, ${SRC:.c=.o})

OBJ_LFT		=	$(addprefix ${OBJ_LFT_DIR}/, ${SRC_LFT:.c=.o})

# ############## #
# FLAGS COMMANDS #
# ############## #

CFLAGS		=	-Wall -Wextra -Werror

# ######## #
# COMMANDS #
# ######## #

all: ${NAME}

${NAME}: create_dirs ${OBJ_LFT} ${OBJ}
	@gcc -pthread -I ${INCLUDES} ${CFLAGS} ${OBJ} ${OBJ_LFT} -o $@
	@echo "${GREEN}${NAME} is up to date!${DEFAULT}"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@gcc -pthread -I ${INCLUDES} ${CFLAGS} -c $< -o $@
	@printf "Compiling ${BLUE} %-${NB_CHAR}s ${DEFAULT} =>\t\t${GREEN}OK\
	${DEFAULT}\n" $<

${OBJ_LFT_DIR}/%.o: ${SRC_LFT_DIR}/%.c
	@gcc -pthread -I ${INCLUDES} ${CFLAGS} -c $< -o $@
	@printf "Compiling ${BLUE} %-${NB_CHAR}s ${DEFAULT} =>\t\t${GREEN}OK\
	${DEFAULT}\n" $<

create_dirs:
	@mkdir -p ${OBJ_DIR} ${OBJ_LFT_DIR}
	@mkdir -p ${OBJ_DIR}/${PHILO} ${OBJ_LFT_DIR}/${FT_PUT} ${OBJ_LFT_DIR}\
	/${FTS_LST} ${OBJ_DIR}/${FTS_ADD} ${OBJ_DIR}/${ARIST}

clean:
	@rm -rf ${OBJ_DIR} ${OBJ_LFT_DIR}
	@echo "${RED}Cleaning up object files in ${OBJ_DIR} and ${OBJ_LFT_DIR}...\
	${DEFAULT}"

fclean: clean
	@rm -f ${NAME}
	@echo "${RED}Removed ${NAME}${DEFAULT}"

norminette:
	@echo "${YELLOW}\nChecking norm for ${NAME}...${DEFAULT}"
	@norminette -R CheckForbiddenSourceHeader ${SRC_DIR} ${SRC_LFT_DIR} \
	${INCLUDES}
	@echo "\nCheck for ${BLUE}${NAME}\t${DEFAULT}\t=>\t${GREEN}OK${DEFAULT}"

re: fclean all
	@echo "${RED}Cleaned and Rebuilt Everything for ${NAME}!${DEFAULT}"
