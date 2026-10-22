NAME	= libft.a

SDIR	= srcs
INC	= includes
HDR	= $(INC)/ft.h
SRC	= $(SDIR)/ft_putchar.c \
		$(SDIR)/ft_swap.c \
		$(SDIR)/ft_putstr.c \
		$(SDIR)/ft_strlen.c \
		$(SDIR)/ft_strcmp.c 
OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c $(HDR)
	cc $(CFLAGS) -I$(INC) -c $< -o $@

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re
