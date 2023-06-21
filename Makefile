# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 15:49:32 by mdiez-as          #+#    #+#              #
#    Updated: 2023/06/21 18:12:08 by mdiez-as         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/client.c src/server.c

OBJS = ${SRCS:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM = rm -rf

all: $(server) $(client)

bonus: $(server) $(client)

server : server.o printf
	$(CC) -o $@ $< -Llibftprintf -lftprintf

client : client.o printf
	$(CC) -o $@ $< -Llibftprintf -lftprintf

%.o: %.c
	$(CC) -c $(CFLAGS) $?

printf:
	make -C libftprintf

clean :
		rm -f $(OBJECTS)
		make -C libftprintf clean

fclean : clean
		rm -f server client printf/libftprintf

re : fclean all

.PHONY:		all clean fclean re
