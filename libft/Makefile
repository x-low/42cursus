# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlow <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 17:01:50 by xlow              #+#    #+#              #
#    Updated: 2023/09/12 20:47:35 by xlow             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			 ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			 ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			 ft_atoi.c ft_calloc.c ft_strdup.c
OBJS = $(SRCS:.c=.o)
CC = cc -Wall -Wextra -Werror -c
LIBC = ar rc
LIBR = ranlib
RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS)
			$(LIBR) $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
