
NAME1		=	push_swap

NAME2		=	checker

# *** #
# DIR #
# *** #

DIRSRC		= ./srcs/
DIRINC		= ./includes/
DIRSORT		= sort/
DIRCHECKER	= checker/
DIRGNL		= get_next_line/
DIRCHECK	= fts_check/
DIRADDS		= fts_add/
DIRMOVES	= fts_moves/

# ******* #
# FILES c #
# ******* #

SRCTEST		=	${DIRSRC}${DIRCHECKER}loop_moves.c \
				${DIRSRC}${DIRCHECKER}checker.c

SRCMAIN		=	${DIRSRC}main.c

SRC			=	${DIRSRC}${DIRGNL}get_next_line.c \
				${DIRSRC}${DIRGNL}get_next_line_utils.c \
				${DIRSRC}${DIRCHECK}fts_check.c \
				${DIRSRC}${DIRMOVES}moves.c \
				${DIRSRC}${DIRMOVES}moves_2.c \
				${DIRSRC}${DIRSORT}fts_sort.c \
				${DIRSRC}${DIRSORT}big_sort.c \
				${DIRSRC}${DIRSORT}little_sort.c \
				${DIRSRC}${DIRADDS}fts_tab.c \
				${DIRSRC}${DIRADDS}fts_add.c

# ******* #
# FILES o #
# ******* #

OBJ			=	${SRC:.c=.o}

OBJTEST		=	${SRCTEST:.c=.o}

OBJMAIN		=	${SRCMAIN:.c=.o}

# ############## #
# FLAGS COMMANDS #
# ############## #

CFLAGS		=	-Wall -Wextra -Werror

# ######## #
# COMMANDS #
# ######## #

.c.o:
				@gcc ${CFLAGS} -I ${DIRINC} -c $< -o ${<:.c=.o}
				@printf "\e[32;3m.\e[0m"

all: 		${NAME1}

${NAME1}:	${OBJ} ${OBJMAIN}
				@gcc ${CFLAGS} ${OBJ} ${OBJMAIN} -o ${NAME1}
				@printf "\n\e[32;3m$@ successfully build\e[0m\n"

${NAME2}:	${OBJ} ${OBJTEST}
				@gcc ${CFLAGS} ${OBJ} ${OBJTEST} -o ${NAME2}
				@printf "\n\e[32;3m$@ successfully build\e[0m\n"

clean:
				@rm -f ${OBJ} ${OBJMAIN} ${OBJTEST}
				@printf "\e[31;3mClean files\e[0m\n"

fclean: 	clean
				@rm -f ${NAME1} ${NAME2}
				@printf "\e[31;3mClean exec\e[0m\n"

re: 		fclean all

global1: 	${NAME1} ${NAME2} clean

global2: 	${NAME1} ${NAME2}
