SRC = ./ft_printf.c\
	./ft_putchar.c\
	./ft_putnbr_hex.c\
	./ft_putnbr_unsigned.c\
	./ft_putnbr.c\
	./ft_putptr.c\
	./ft_putstr.c\
	./ft_strchr.c\

CC= gcc

FLAGS= -Wall -Wextra -Werror -I. 

OBJ=$(SRC:.c=.o)

NAME= ft_printf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re