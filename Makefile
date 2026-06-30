NAME = push_swap.a

CC = cc
CFLAGS = -g -fsanitize=address

SRCS = ft_printf.c ft_printf_utils.c push_swap_simple.c push_swap_opp.c \
	   push_swap_opr.c push_swap_oprr.c push_swap_ops.c push_swap_utils.c \
	   push_swap.c push_swap_lists.c push_swap_parsing.c push_swap_valid.c \
	   ft_split.c push_swap_medium.c

OBJS = $(SRCS:.c=.o)

TEST = testswap

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

test: $(NAME) push_swap.c
	$(CC) push_swap.c $(NAME) -o $(TEST) -g -fsanitize=address

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re test
