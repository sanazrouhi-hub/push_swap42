NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_FILES   = main.c \
              parser.c \
			  ft_split.c \
              parse_utils.c \
              stack_utils.c \
              stack.c \
              operations_push.c \
              operations_reverse_rotate.c \
              operations_rotate.c \
              operations_swap.c \
              target_find.c \
              cost_calculator.c \
              execute_cheapest.c \
              big_sort.c \
              small_sort.c \
			  chunk_sort.c \
			  radix_sort.c \
              adaptive.c \
			  strategy.c

OBJS        = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)


re: fclean all
.PHONY: all clean fclean re
