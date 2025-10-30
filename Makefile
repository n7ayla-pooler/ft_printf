CC = cc
CFlags = -Wall -Wextra -Werror
SRC = ft_printf.c printf_utils.c printf_utils2.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFlags) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re