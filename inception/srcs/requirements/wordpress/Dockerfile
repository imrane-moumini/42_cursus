FROM debian:buster
RUN apt update -y
RUN apt upgrade -y
RUN apt-get -y install wget
RUN apt-get install -y php7.3
RUN php-fpm
RUN php-mysql
RUN mariadb-client
RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www
RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz
RUN	chown -R root:root /var/www/wordpress
COPY    ./conf/www.conf    /etc/php/7.3/fpm/pool.d/www.conf
RUN RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp
COPY tools/auto-config.sh /auto-config.sh
ENTRYPOINT ["bash", "/auto-config.sh"]
#pb trouve pas php, voir si c que sur ma machine