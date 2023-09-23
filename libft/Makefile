# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlow <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 17:01:50 by xlow              #+#    #+#              #
#    Updated: 2023/09/23 20:47:24 by xlow             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			 ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			 ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			 ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			 ft_printf.c printf_helpers.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstmap.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
CC = cc -Wall -Wextra -Werror -c
LIBC = ar rc
LIBR = ranlib
RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME) bonus

$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS)
			$(LIBR) $(NAME)

bonus: $(OBJS) $(BOBJS)
			$(LIBC) $(NAME) $(BOBJS) $(OBJS)
			$(LIBR) $(NAME)

clean:
		$(RM) $(OBJS) $(BOBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
