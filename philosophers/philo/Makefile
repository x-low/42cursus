# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlow <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:22:07 by xlow              #+#    #+#              #
#    Updated: 2024/04/18 17:11:52 by xlow             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philo.c \
	   philo_args.c \
	   philo_init.c \
	   philo_life.c \
	   philo_utils.c \
	   philo_monitor.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Werror -Wextra -c -g
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	cc -Wall -Werror -Wextra -g $(OBJS) -o $(NAME)

debug: $(OBJS)
	cc -Wall -Werror -Wextra -g -fsanitize=thread $(OBJS) -o $(NAME)

.c.o:
	$(CC) $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
