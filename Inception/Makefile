##############
# DATAS		 #
##############

SRCS 			=	./srcs
DOCKER			=	sudo docker
COMPOSE 		=	cd srcs/ && sudo docker-compose
DATA_PATH 		=	/home/hgoorick/data

##############
# ASCII DECO #
##############

DEFAULT			=	\033[0;39m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
BLUE_UNDERLINE	=	\033[4;34m
START_FIRST		=	\033[999D

#Create and start the dockers without all details
all		:	build
			@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}${YELLOW}%-30s${DEFAULT}" "Directory creation" "in progress"
			@sudo mkdir -p $(DATA_PATH) $(DATA_PATH)/wordpress $(DATA_PATH)/database
			@printf "${START_FIRST}${BLUE}%-30s%-30s${DEFAULT}\n" "Directory creation" "is done"

			@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}${YELLOW}%-30s${DEFAULT}" "Redirect" "in progress"
			@sudo chmod 777 /etc/hosts
			@sudo echo "127.0.0.1 hgoorick.42.fr" >> /etc/hosts
			@sudo echo "127.0.0.1 www.hgoorick.42.fr" >> /etc/hosts
			@printf "${START_FIRST}${BLUE}%-30s%-30s${DEFAULT}\n" "Redirect" "is done"

			@$(COMPOSE) up -d

#Create and start the dockers with all details
show_me	:	
			$(COMPOSE) build

			sudo mkdir -p $(DATA_PATH) $(DATA_PATH)/wordpress $(DATA_PATH)/database

			sudo chmod 777 /etc/hosts
			sudo echo "127.0.0.1 hgoorick.42.fr" >> /etc/hosts
			sudo echo "127.0.0.1 www.hgoorick.42.fr" >> /etc/hosts

			$(COMPOSE) up -d

#build or rebuild services
build	:
			@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}${YELLOW}%-30s${DEFAULT}" "Building dockers" "in progress"
			@$(COMPOSE) build --quiet
			@printf "${START_FIRST}${BLUE}%-30s%-30s${DEFAULT}\n" "Building dockers" "is done"


# Creates and start containers
up:
			@${COMPOSE} up -d 

# Stops containers and removes containers, networks, volumes, and images created with up
down	:
			@$(COMPOSE) down

# Pause containers
pause:
			@$(COMPOSE) pause

# Unpause containers 
unpause:
			@$(COMPOSE) unpause

# down and make sure every containers are deleted
clean	:
			@$(COMPOSE) down -v --rmi all --remove-orphans

# cleans and makes sure every volumes, networks and image are deleted
fclean	:	clean
			@$(DOCKER) system prune --volumes --all --force
			@sudo rm -rf $(DATA_PATH)
			@$(DOCKER) network prune --force
			@echo docker volume rm $(docker volume ls -q)
			@$(DOCKER) image prune --force

# $(DOCKER) volume prune --force
re		:	fclean all

.PHONY : all build up down pause unpause clean fclean re show_me