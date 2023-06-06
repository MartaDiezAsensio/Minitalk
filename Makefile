# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 21:43:54 by mdiez-as          #+#    #+#              #
#    Updated: 2023/06/06 21:47:01 by mdiez-as         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server

SRCC_FILES = client.c
SRCS_FILES = server.c

SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))

OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C printf
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) printf/$(PRINTF) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C printf
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) printf/$(PRINTF) -o $(NAMES)

clean :
		//@make clean -C printf
		${RM} ${OBJC}
		${RM} ${OBJS}

fclean : clean
		//@make fclean -C printf
		${RM} $(NAMEC)
		${RM} $(NAMES)

re : fclean all

.PHONY:		all bonus clean fclean re