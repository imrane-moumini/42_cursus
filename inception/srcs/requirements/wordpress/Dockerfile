FROM debian:buster
RUN apt-get update && apt-get upgrade -y \
    && apt-get -y install wget \
    && apt-get install -y php7.3 php-fpm php-mysql mariadb-client \

    && wget https://wordpress.org/wordpress-6.0.tar.gz -P /var/www \
    && cd /var/www && tar -xzf wordpress-6.0.tar.gz && rm wordpress-6.0.tar.gz \
    && chown -R root:root /var/www/wordpress \

    && wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp
COPY    ./conf/www.conf    /etc/php/7.3/fpm/pool.d/www.conf
COPY tools/auto-config.sh /auto-config.sh
ENTRYPOINT ["bash", "/auto-config.sh"]
#pb trouve pas php, voir si c que sur ma machine