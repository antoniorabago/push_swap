NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c push_swap_alg1.c push_swap_opp.c \
	   push_swap_opr.c push_swap_oprr.c push_swap_ops.c push_swap_utils.c \
	   push_swap.c push_swap_lists.c

OBJS = $(SRCS:.c=.o)

TEST = testswap

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

test: $(NAME) push_swap.c
	$(CC) push_swap.c $(NAME) -o $(TEST)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re test
