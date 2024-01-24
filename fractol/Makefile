# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlow <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 08:41:29 by xlow              #+#    #+#              #
#    Updated: 2024/01/23 15:38:23 by xlow             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = closing.c fractol.c hooks.c julia.c mandelbrot.c math.c
OBJS = $(SRCS:.c=.o)
CC = cc -Wall -Werror -Wextra -c
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cc $(OBJS) libft/libft.a libmlx_Linux.a -lXext -lX11 -o $(NAME)

.c.o:
	$(CC) $< -o $(<:.c=.o)

clean:
	make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all
