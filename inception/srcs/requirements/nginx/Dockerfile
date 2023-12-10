FROM debian:buster
RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install nginx openssl -y \
    && mkdir -p /etc/nginx/ssl \  
    && openssl req -newkey rsa:4096 -nodes -x509 \
       -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=imoumini.42.fr/UID=imoumini" \
       -out /etc/nginx/ssl/inception.crt \
       -keyout /etc/nginx/ssl/inception.key \
    && mkdir var/www/wordpress \
    && chmod 755 /var/www/wordpress \
    && chown -R www-data:www-data /var/www/wordpress

COPY conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE	443
CMD [ "nginx", "-g", "daemon off;" ]


