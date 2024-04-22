NAME = pipex
B_NAME = pipex

SRC_DIR = mandatory
BSRC_DIR = bonus

SRCS = cleanup_pipex.c init_pipex.c pipex.c processes_pipex.c

B_SRCS = cleanup_pipex_bonus.c init_pipex_bonus.c pipex_bonus.c \
				 processes_pipex_bonus.c here_doc_bonus.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))
B_OBJS = $(addprefix $(BSRC_DIR)/, $(B_SRCS:.c=.o))

CC = cc -Wall -Werror -Wextra -g
RM = rm -rf

vpath %.c $(SRC_DIR) $(BSRC_DIR)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

all: $(NAME)

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
