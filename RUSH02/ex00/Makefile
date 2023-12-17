SRC = dictionary.c input.c main.c output.c translator.c string.c file.c arrays.c arrays2.c mask.c
OBJ = $(SRC:%.c=%.o)
NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean test

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)
	norminette

clean:
	rm $(wildcard $(OBJ)) # I also modified the clean rule

fclean: clean
	rm $(NAME)
