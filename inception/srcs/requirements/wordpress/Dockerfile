FROM debian:buster
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y wget
RUN apt-get install -y php7.3 php-fpm php-mysql

RUN wget https://wordpress.org/wordpress-6.4.1.tar.gz  -P /var/www/html\
    && cd /var/www/html && tar -xzf /var/www/html/wordpress-6.4.1.tar.gz && rm /var/www/html/wordpress-6.4.1.tar.gz \

    && wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

RUN chown -R www-data:www-data /var/www/*
RUN chmod -R 755 /var/www/*

EXPOSE 9000

COPY    ./conf/www.conf    /etc/php/7.3/fpm/pool.d/www.conf
COPY tools/auto-config.sh /auto-config.sh

RUN chmod +x /auto-config.sh

ENTRYPOINT ["bash", "/auto-config.sh"]
