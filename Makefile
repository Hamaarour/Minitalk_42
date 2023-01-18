# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 15:52:36 by hamaarou          #+#    #+#              #
#    Updated: 2023/01/17 18:39:49 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= server client
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=sup/count_nbr.c sup/ft_putchar.c sup/ft_putnbr.c sup/ft_putstr.c  \
	sup/ft_strlen.c sup/ft_putnbr_hex.c sup/ft_printf.c sup/ft_atoi.c

SERVER=server
CLIENT=client

OBJ= $(SRCS:.c=.o)

all : $(NAME)

.PHONY= all clean fclean re

$(SERVER): server.c $(OBJ)
	$(CC) $(CFLAGS) server.c $(OBJ) -o $(SERVER)

$(CLIENT): client.c $(OBJ)
	$(CC) $(CFLAGS) client.c $(OBJ) -o $(CLIENT)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME) $(CLIENT) $(SERVER)

re:fclean all
