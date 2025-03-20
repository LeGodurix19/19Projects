#####################################################
# Setup												#
#####################################################

FROM	alpine:3.14
RUN		apk update
RUN		apk add --no-cache --quiet --update curl bash vim
RUN		apk add --no-cache --quiet --update mariadb-client
RUN		apk add --no-cache --quiet --update php7 php-phar php-json php-curl php-fpm php-mysqli php-iconv

#####################################################
# Create dir										#
#####################################################

RUN		mkdir -p /var/www/wordpress 

#####################################################
# Dl wp cli and add access permissions				#
#####################################################

RUN		curl https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar --output /usr/bin/wp 

#####################################################
# Add access permissions							#
#####################################################

RUN		chmod +x ./usr/bin/wp 

#####################################################
# Dl wp with wp cli									#
#####################################################

RUN		wp core download --path=/var/www/wordpress

#####################################################
# Modif workdir										#
#####################################################

WORKDIR /var/www/wordpress

#####################################################
# Copy files										#
#####################################################

COPY	config/wp-config.php /config/wp-config
COPY	./tools/entrypoint.sh /tmp/entrypoint.sh

#####################################################
# Add access permissions							#
#####################################################

RUN		chmod +x /tmp/entrypoint.sh

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]