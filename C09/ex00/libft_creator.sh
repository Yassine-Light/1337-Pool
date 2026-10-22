#! /bin/bash
cc -Wall -Wextra -Werror -c  ft_strcmp.c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c
ar rcs libft.a ft_strcmp.o ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o
rm -rf *.o
