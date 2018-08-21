# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/26 13:43:39 by lode-spi          #+#    #+#              #
#    Updated: 2018/07/03 14:19:35 by lode-spi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
SRCS = free_factory.c fill_map.c fillit.c file_validity.c file_reader.c build_list.c build_map.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) -c $(SRCS) 
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJS) main.c -L../libft/ ../libft/libft.a

clean :
	@rm -f $(OBJS) 

fclean : clean
	@rm -f $(NAME)

re : fclean all
