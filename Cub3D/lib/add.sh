# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    add.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 11:22:25 by hugoorickx        #+#    #+#              #
#    Updated: 2022/03/30 11:22:25 by hugoorickx       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/env bash

read -p "Nb files: " nb_files
x=0
while [ $x -lt $nb_files ]
do
    read -p 'Filename: ' file_name
    echo 'SRC += '$file_name >> '../datas_makefile/libft_datas.mk'
    ((x++))
done
echo ""