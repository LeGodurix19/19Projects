DEFAULT			=	\033[0;39m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
START_FIRST		=	\033[999D

NB_CHAR		=	30

FAST = 0.00001

NAME = webserv

FLAGS = -Wall -Wextra -Werror -std=c++11 -I includes

INCLUDES	=	./includes
SRCS_DIR = src
OBJS_DIR = obj

SRCS =	main.cpp \
		Client.class.cpp \
		parse_conf.cpp \
		Requete.class.cpp \
		Conf.class.cpp\
		Server.class.cpp \
		Socket.class.cpp \
		cgi.cpp \
		Servers.class.cpp \
		Location.class.cpp \

OBJS = $(addprefix ${OBJS_DIR}/,${SRCS:.cpp=.o})

all: create_dir $(OBJS)
		@c++ $(FLAGS) $(OBJS) -o $(NAME)
		@printf "${START_FIRST}${GREEN}%-${NB_CHAR}s${DEFAULT}[OK]${DEFAULT}" "COMPILATION"

${OBJS_DIR}/%.o:${SRCS_DIR}/%.cpp
		@printf "${START_FIRST}${GREEN}%-${NB_CHAR}s${DEFAULT}[%-${NB_CHAR}s]${DEFAULT}" "COMPILATION" "$<"
		@c++ ${FLAGS} -I ${INCLUDES} -c $< -o $@
		@sleep $(FAST)
		
clean:
		@rm -rf $(OBJS)
		@printf "${RED}%-${NB_CHAR}s${DEFAULT}[OK]${DEFAULT}\n" "CLEAN"

fclean: clean
		@rm -rf $(NAME)
		@rm -rf $(OBJS_DIR)
		@printf "${RED}%-${NB_CHAR}s${DEFAULT}[OK]${DEFAULT}\n" "FCLEAN"

re: fclean all

create_dir:
		@mkdir -p $(OBJS_DIR)

.PHONY: all fclean clean re