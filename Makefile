NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_FILES   = main.c \
              parser.c \
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
              small_sort.c

OBJS        = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"


%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@echo "Object files cleaned."

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@echo "$(NAME) removed."


re: fclean all
.PHONY: all clean fclean re
