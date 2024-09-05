CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -O0
SRC			= bitflags.c \
			conv_factory.c \
			conversion_functions.c \
			flag_functions.c \
			ft_printf.c \
			general_functions.c \
			handle_escape.c \
			string_precision.c
			
OBJ			= $(SRC:.c=.o)
EXT			= libft/libft.a
NAME		= test.a



all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< 

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ) $(EXT)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re