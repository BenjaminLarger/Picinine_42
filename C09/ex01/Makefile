# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blarger <blarger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 14:06:20 by blarger           #+#    #+#              #
#    Updated: 2023/10/05 16:53:07 by blarger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
SRCS = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
all: libft.a

libft.a: $(OBJS)
	ar rcs libft.a $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Iincludes

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a
	
re: fclean all