#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/22 11:35:22 by vpoltave          #+#    #+#              #
#    Updated: 2017/07/05 09:16:37 by vpoltave         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = 	./libft/libft.a
OBJECTS =	./src/main.o					\
            ./src/vp_ants.o                \

.PHONY: libft

all: $(NAME)

$(NAME) : $(OBJECTS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

libft:
	make -C ./libft

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECTS)
	make clean -C ./libft
fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
re: fclean all