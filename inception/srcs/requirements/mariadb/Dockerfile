FROM debian:buster

RUN apt update -y && apt upgrade -y && apt install mariadb-server -y
RUN apt-get install -y mariadb-client
RUN apt-get install -y procps

COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/mariadb.sh /mariadb.sh

RUN mkdir -p /var/run/mysqld
RUN mkdir -p /var/lib/mysql
RUN chown mysql:mysql /var/run/mysqld/
RUN chmod -R 755 /var/run/mysqld/
RUN chown mysql:mysql /var/lib/mysql/
RUN chmod -R 755 /var/lib/mysql/

EXPOSE 3306
RUN chmod +x ./mariadb.sh
ENTRYPOINT ["bash", "mariadb.sh"]



