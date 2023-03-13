# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 13:33:34 by xalbizu-          #+#    #+#              #
#    Updated: 2023/03/13 16:35:02 by xalbizu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = main.c utils.c
SRC = $(FILES:.c=.o)

NAME = philo
CC = gcc
CFLAGS = -Werror -Wall  -Wextra #-g3 -fsanitize=address 
 

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all