# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 15:56:17 by aziabkin          #+#    #+#              #
#    Updated: 2018/04/23 16:03:43 by aziabkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LBF  = libft
SRCS = reader.c    \
       validator.c \
       main.c      \
       solution.c  \
	   struct.c
OFILES = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OFILES)
	make -C libft re
	gcc $(FLAGS) -o $(NAME) -I $(LBF) -L ./libft/ -lft $(OFILES)

%.o:%.c
	gcc $(FLAGS) -o $@ -c $< -I ./libft/

clean:
	rm -f $(OFILES)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
re: fclean all
