# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/25 13:38:37 by mbenkhat          #+#    #+#              #
#    Updated: 2021/12/25 13:38:38 by mbenkhat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : server client

server : server.c utils.c
	$(CC) $(FLAGS) -o $@ $< utils.c

client : client.c utils.c
	$(CC) $(FLAGS) -o $@ $< utils.c

bonus : server_bonus client_bonus

server_bonus : server_bonus.c utils.c
	$(CC) $(FLAGS) -o $@ $< utils.c

client_bonus : client_bonus.c utils.c
	$(CC) $(FLAGS) -o $@ $< utils.c

clean :
	rm -f server client server_bonus client_bonus

fclean : clean

re: fclean all