# Define variables
DOCKER_COMPOSE_FILE=./srcs/docker-compose.yml
DATA_DIR=/home/imoumini/data

# Phony targets
.PHONY: all clean fclean stop setup 

# Default target
all:
	@if [ $$(sudo docker-compose -f $(DOCKER_COMPOSE_FILE) images | wc -l) -eq 1 ]; then \
		echo "Starting containers..."; \
		sudo mkdir -p $(DATA_DIR)/wordpress $(DATA_DIR)/mariadb; \
		sudo docker-compose -f $(DOCKER_COMPOSE_FILE) up -d --build; \
	else \
		echo "Containers already build"; \
	fi


up :
	sudo docker-compose -f $(DOCKER_COMPOSE_FILE) up -d
	
# Clean up containers
clean: stop
	sudo docker-compose -f $(DOCKER_COMPOSE_FILE) down -v

# Remove data directories and clean up containers
fclean: clean
	sudo rm -rf $(DATA_DIR)/wordpress $(DATA_DIR)/mariadb; sudo docker stop $(shell sudo docker ps -qa); sudo docker rm $(shell sudo docker ps -qa); sudo docker rmi -f $(shell sudo docker images -qa); sudo docker rm $(shell sudo docker volume ls -q); sudo docker network rm $(shell sudo docker network ls -q) 2> /dev/null

# Stop containers
stop:
	sudo docker-compose -f $(DOCKER_COMPOSE_FILE) stop
