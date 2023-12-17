SRC = main.c help.c
OBJ = $(SRC:%.c=%.o)
NAME = ft_cat
CC = cc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean test

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)
clean:
	rm $(wildcard $(OBJ))

fclean: clean
	rm $(NAME)
