# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druina <druina@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 13:54:07 by druina            #+#    #+#              #
#    Updated: 2023/02/02 08:46:57 by druina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

NAMEC = client

SSRC = server.c

CSRC = client.c

SPATH = $(addprefix ./src/, $(SSRC))

CPATH = $(addprefix ./src/, $(CSRC))

FLAGS = -Wall -Wextra -Werror

HEADER = ./src/minitalk.h

.PHONY: all clean fclean re

all: $(NAME) $(NAMEC)

$(NAME): $(SPATH) $(CPATH)
	@cd libft && make
	@cd libft && mv libft.a ..
	@cc $(FLAGS) -o $(NAME) $(SPATH) libft.a -I $(HEADER)
	@cc $(FLAGS) -o $(NAMEC) $(CPATH) libft.a -I $(HEADER)

clean:
	@cd libft && make clean
	@rm -f libft.a

fclean: clean
	@rm -f $(NAME) $(NAMEC)
	@cd libft && make fclean



re: fclean all


