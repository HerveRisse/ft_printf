NAME = libftprintf.a
TEST = ft_printf_test

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
       ft_printf_utils.c \
       ft_printf_format.c

OBJS = $(SRCS:.c=.o)

TEST_SRC = main.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_SRC:.c=.o)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

test: $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(NAME) -o $(TEST)
	./$(TEST)

.PHONY: all clean fclean re test
