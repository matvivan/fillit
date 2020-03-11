#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matvivan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 17:44:17 by matvivan          #+#    #+#              #
#    Updated: 2019/12/10 18:35:07 by matvivan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = main.c check.c fillit.c
NAME = fillit
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make all -C libft/
	gcc $(CFLAGS) -c $(SRC)
	gcc $(SRC:.c=.o) -L libft/ -lft -o $(NAME)

clean:
	@make clean -C libft/
	rm -f $(SRC:.c=.o)

fclean: clean
	@make fclean -C libft/
	rm -f $(NAME)

re: fclean all