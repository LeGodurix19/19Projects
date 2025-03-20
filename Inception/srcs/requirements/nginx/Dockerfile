#####################################################
# Setup												#
#####################################################

FROM	alpine:3.14
RUN		apk update
RUN		apk add --no-cache --quiet --update nginx
RUN		apk add --no-cache --quiet --update openssl

#####################################################
# Create dir for nginx								#
#####################################################

RUN		mkdir -p /etc/nginx/ssl /var/run/nginx

#####################################################
# Gen certif for the domaine name					#
#####################################################

RUN 	openssl req -x509 -nodes -out /etc/nginx/ssl/hgoorick.42.fr.crt -keyout /etc/nginx/ssl/hgoorick.42.fr.key -subj "/C=FR/ST=IDF/L=Bruxelles/O=42/OU=42/CN=hgoorick.42.fr/UID=hgoorick"

#####################################################
# Copy my own conf file								#
#####################################################

COPY	config/nginx.conf /etc/nginx/http.d/default.conf

#####################################################
# Expose only one port 443							#
#####################################################

EXPOSE	443

#####################################################
# Exec cmd nginx without daemon						#
#####################################################

CMD	[ "nginx", "-g", "daemon off;" ]
