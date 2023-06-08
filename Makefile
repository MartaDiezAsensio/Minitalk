# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 15:49:32 by mdiez-as          #+#    #+#              #
#    Updated: 2023/06/08 16:19:30 by mdiez-as         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server

SRCC =	client.c
SRCS =	server.c


OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE 	= ./header.h
RM = rm -rf

all:	$(NAMEC) $(NAMES)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAG) -c $< -o $@

clean :
		${RM} ${OBJC}
		${RM} ${OBJS}

fclean : clean
		${RM} $(NAMEC)
		${RM} $(NAMES)

re : fclean all

$(NAME) : $(OBJS) $(OBJC)
	$(AR) $(ARFLAGS) $@ $^

.PHONY:		all clean fclean re
