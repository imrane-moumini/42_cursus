all: 
	sudo mkdir -p /home/imoumini/data/mariadb
	sudo mkdir -p /home/imoumini/data/wordpress
	sudo docker compose -f ./srcs/docker-compose.yml build
	sudo docker compose -f ./srcs/docker-compose.yml up -d

logs:
	sudo docker logs wordpress
	sudo docker logs mariadb
	sudo docker logs nginx

clean:
	sudo docker container stop nginx mariadb wordpress
	sudo docker network rm inception

fclean: clean
	sudo rm -rf /home/imoumini/data/mariadb/*
	sudo rm -rf /home/imoumini/data/wordpress/*
	sudo docker system prune -af

re: fclean all

.Phony: all logs clean fclean