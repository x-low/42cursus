# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlow <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 20:32:44 by xlow              #+#    #+#              #
#    Updated: 2023/09/21 11:07:47 by xlow             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c printf_helpers.c
OBJS = $(SRCS:.c=.o)
CC = cc -Wall -Wextra -Werror -c
LIBC = ar rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	make -C libft
	mv libft/libft.a $(NAME)
	$(LIBC) $(NAME) $(OBJS)

.c.o:
	$(CC) $< -o $(<:.c=.o)

clean:
	make -C libft clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all
