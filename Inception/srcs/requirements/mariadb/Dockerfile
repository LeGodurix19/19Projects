#####################################################
# Setup												#
#####################################################

FROM	alpine:3.14
RUN		apk update
RUN		apk add --no-cache --quiet --update mariadb mariadb-client vim

#####################################################
# Create dir for deamon								#
#####################################################

RUN 	mkdir -p /var/lib/mysqld /run/mysqld

#####################################################
# Copy config files     							#
#####################################################

COPY	./config/create_db.sql /tmp/create_db.sql
COPY	./tools/entrypoint.sh ./
COPY 	./config/mariadb-server.cnf /etc/my.cnf.d/

#####################################################
# Install DB and auth								#
#####################################################

RUN		mariadb-install-db --datadir=/var/lib/mysql --auth-root-authentication-method=normal

#####################################################
# Add access permissions							#
#####################################################

RUN 	chmod +x ./entrypoint.sh
RUN		chown -R mysql:mysql /var/lib/mysql 
RUN 	chown -R mysql:mysql /run/mysqld

#####################################################
# Exec script										#
#####################################################

ENTRYPOINT [ "sh", "entrypoint.sh" ]