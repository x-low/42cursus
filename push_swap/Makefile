NAME = push_swap
B_NAME = checker

SRC_DIR = mandatory
BSRC_DIR = bonus

SRCS = arg_validation.c operations.c push_swap.c push_swap_utils.c \
			 sort_big.c sort_element_finders.c sort_small.c

B_SRCS = checker.c checker_arg_validation.c checker_operations.c checker_utils.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))
B_OBJS = $(addprefix $(BSRC_DIR)/, $(B_SRCS:.c=.o))

CC = cc -Wall -Werror -Wextra -g
RM = rm -rf

vpath %.c $(SRC_DIR) $(BSRC_DIR)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

all: $(NAME) bonus

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(OBJS) libft/libft.a -o $(NAME)

bonus: $(B_OBJS) libft/libft.a
	$(CC) $(B_OBJS) libft/libft.a -o $(B_NAME)

libft/libft.a:
	make -C libft

clean:
	make -C libft clean
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re
