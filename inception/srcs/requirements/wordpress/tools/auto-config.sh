#!bin/bash

#to be sure that teh database exist
sleep 10

# Check if the wp-cli command is installed
if ! [ -x "$(command -v wp)" ]; then
  echo 'Error: wp-cli is not installed. Please install it before running this script.' >&2
  exit 1
fi

# If wp-config.php file does not exist, create it and install WordPress
if [ ! -e /var/www/wordpress/wp-config.php ]; then
	echo "Creating wp-config.php file..."
	wp config create    --allow-root --dbname=$SQL_DATABASE --dbuser=$SQL_USER --dbpass=$SQL_PASSWORD --dbhost=mariadb:3306 --path='/var/www/wordpress'
	echo "Installing WordPress..."
	wp core install --url=$DOMAIN_NAME --title=$SITE_TITLE --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL --allow-root --path='/var/www/wordpress'
	wp user create --allow-root --role=author $USER1_LOGIN $USER1_MAIL --user_pass=$USER1_PASS --path='/var/www/wordpress' >> log.txt
fi

# Create /run/php directory if it doesn't exist
if [ ! -d /run/php ]; then
    mkdir ./run/php
fi

# Start the PHP-FPM process
# PHP-FPM stands for PHP FastCGI Process Manager. It is a PHP extension that allows PHP to operate as a FastCGI process manager for web servers like Nginx
echo "Starting php-fpm..."
/usr/sbin/php-fpm7.3 -F