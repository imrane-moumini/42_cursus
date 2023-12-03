FROM debian:buster
RUN apt update -y
RUN apt upgrade -y
RUN apt install mariadb-server -y
COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/mariadb.sh /mariadb.sh
ENTRYPOINT ["bash", "mariadb.sh"]



#le truc bug le fichier .sock se créer pas, je sais pas si c'est du à ma machine
#faut je teste sur une autre machine

