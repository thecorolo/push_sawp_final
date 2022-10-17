# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinbi- <azinbi-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 00:05:58 by azinbi-           #+#    #+#              #
#    Updated: 2022/10/17 00:49:55 by azinbi-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ft_atoi.c ft_itoa.c operation.c push_swap.c radix.c sorting.c utils.c norm.c  \

OBJS = $(SRCS:.c=.o)

FLAGS = -g -Werror -Wextra -Wall

ASAN = -g -fsanitize=address

$(NAME) :
	gcc -g $(SRCS) $(FLAGS) -o $(NAME)
	
all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)


re: fclean all
 .PHONY : all clean fclean re
