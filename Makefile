# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 15:52:36 by hamaarou          #+#    #+#              #
#    Updated: 2023/01/16 12:06:15 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minitalk
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=


OBJ= $(SRC:.c=.o)

all:$(NAME)

.PHONY= all clean fclean re

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.c:%.o
	$(CC) $(CFLAGS) -c $< -o $@	
clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re:fclean all
