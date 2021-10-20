# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 23:35:17 by rgelin            #+#    #+#              #
#    Updated: 2021/10/19 15:46:49 by rgelin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS = 		./src/server.c

SERVER_OBJS =		$(SERVER_SRCS:%.c=%.o)

CLIENT_SRCS =		./src/client.c

CLIENT_OBJS =		$(CLIENT_SRCS:%.c=%.o)

UTILS_SRCS	=		./utils/ft_atoi.c \
					./utils/ft_calloc.c \
					./utils/ft_isdigit.c \
					./utils/ft_recursive_power.c

UTILS_OBJS	=		$(UTILS_SRCS:%.c=%.o)

PRINTF		=		cd ./utils/ft_printf && make

LIB_PRINTF	=		./utils/ft_printf/libftprintf.a



CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

REMOVE		=		rm -f

SERVER		=		server

CLIENT		=		client



GREEN		=		\x1b[32m

NO_COLOR	=		\x1b[0m



.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		lib $(SERVER) $(CLIENT)
			@echo "$(NO_COLOR)server $(GREEN)ready"
			@echo "$(NO_COLOR)client $(GREEN)ready"

bonus:		lib $(SERVER) $(CLIENT)
			@echo "$(NO_COLOR)server $(GREEN)ready"
			@echo "$(NO_COLOR)client $(GREEN)ready"

lib:		
			@$(PRINTF)
			@echo "$(NO_COLOR)ft_printf $(GREEN)ready$(NO_COLOR)"

$(SERVER):	$(SERVER_OBJS) $(UTILS_OBJS)
			@$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB_PRINTF) $(UTILS_OBJS) -o $(SERVER)
			
$(CLIENT):	$(CLIENT_OBJS) $(UTILS_OBJS)
			@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB_PRINTF) $(UTILS_OBJS) -o $(CLIENT)

clean:
			@ cd ./utils/ft_printf && make clean
			@$(REMOVE) $(SERVER_OBJS) $(CLIENT_OBJS) $(UTILS_OBJS)

fclean:		clean
			@ cd ./utils/ft_printf && make fclean
			@$(REMOVE) $(SERVER) $(CLIENT) $(UTILS_OBJS)

re:			fclean all

.PHONY:		all clean fclean re