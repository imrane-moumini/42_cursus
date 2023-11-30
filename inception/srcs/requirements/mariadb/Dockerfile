FROM debian:buster
RUN apt update -y
RUN apt upgrade -y
RUN apt-get install mariadb-server -y
RUN apt-get install systemd -y
COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
RUN service mysql start
RUN touch /var/run/mysqld/mysqld.sock
RUN chmod 755 /var/run/mysqld/ 
RUN chown mysql:mysql /var/run/mysqld/ 
RUN chmod 755 /var/run/mysqld/mysqld.sock 
RUN chown mysql:mysql /var/run/mysqld/mysqld.sock
RUN systemctl restart mysql
RUN mysql -e ""

