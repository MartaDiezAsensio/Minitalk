# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 19:17:14 by mdiez-as          #+#    #+#              #
#    Updated: 2023/06/22 13:16:25 by mdiez-as         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server

BONUS_NAMEC = client_bonus
BONUS_NAMES = server_bonus

PRINTF = libftprintf.a

SRCC_FILES = client.c
SRCS_FILES = server.c

BONUSC_FILES = client_bonus.c 
BONUSS_FILES = server_bonus.c

SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))

BONUSC = $(addprefix $(SRC_DIR), $(BONUSC_FILES))
BONUSS = $(addprefix $(SRC_DIR), $(BONUSS_FILES))

OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}

OBJBC = ${BONUSC:.c=.o}
OBJBS = ${BONUSS:.c=.o}

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


bonus : $(BONUS_NAMEC) $(BONUS_NAMES)

$(BONUS_NAMEC) : $(OBJBC)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJBC)  $(INCLUDE)  ft_printf/$(PRINTF) -o $(BONUS_NAMEC)

$(BONUS_NAMES) : $(OBJBS)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJBS)  $(INCLUDE)  ft_printf/$(PRINTF) -o $(BONUS_NAMES)

clean:
	@make clean -C ft_printf
	$(RM) $(OBJC)
	$(RM) $(OBJS)
	${RM} ${OBJBC}
	${RM} ${OBJBS}

fclean: clean
	@make fclean -C ft_printf
	$(RM) $(NAMEC)
	$(RM) $(NAMES)
	${RM} $(BONUS_NAMEC)
	${RM} $(BONUS_NAMES)
	$(RM) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
