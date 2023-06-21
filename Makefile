# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 19:17:14 by mdiez-as          #+#    #+#              #
#    Updated: 2023/06/21 19:36:28 by mdiez-as         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server

PRINTF = libftprintf.a

SRCC_FILES = client.c
SRCS_FILES = server.c

SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))

OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I includes
RM = rm -rf

all: $(NAMEC) $(NAMES)

$(NAMEC): $(OBJC)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) ft_printf/$(PRINTF) -o $(NAMEC)

$(NAMES): $(OBJS)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) ft_printf/$(PRINTF) -o $(NAMES)

clean:
	@make clean -C ft_printf
	$(RM) $(OBJC)
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C ft_printf
	$(RM) $(NAMEC)
	$(RM) $(NAMES)
	$(RM) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
