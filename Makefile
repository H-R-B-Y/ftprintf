NAME			= libftprintf.a

SRC				= bitflags.c \
				conv_factory.c \
				conversion_functions.c \
				flag_functions.c \
				ft_printf.c \
				general_functions.c \
				escape_parsing.c \
				precision.c \
				generators.c

OBJ				= $(SRC:.c=.o)
LIBFT_DIR		= libft
LIBFT			= libft/libft.a

HEADER			= ft_printf.h

TEST_DIR		= testing

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -O0


# All target
all:			$(NAME) Makefile $(HEADER)

# Compile objects for named sources.
.c.o:
		
		$(CC) $(CFLAGS) -c $< 

# Compile IDK something, i dont think we need to compile this one LOL
$(NAME):		$(OBJ) $(LIBFT)
		
		cp $(LIBFT) .
		mv libft.a $(NAME)
		ar -rc $(NAME) $(OBJ)


# Compile LIBFT dependency
$(LIBFT):
		
		$(MAKE) --directory $(LIBFT_DIR)

bonus:				$(NAME)

# Clean
clean:
		
		$(MAKE) --directory $(LIBFT_DIR) clean
		rm -f *.o

# Full Clean
fclean:			clean
		
		$(MAKE) --directory $(LIBFT_DIR) fclean
		rm -f $(NAME)

# DELETE LATER
quicktest:		$(NAME) $(LIBFT) quicktest.c

		$(CC) $(CFLAGS) quicktest.c $(NAME) -o $(TEST_DIR)/quicktest.out

test:				quicktest

		@$(TEST_DIR)/quicktest.out ft | cat -A > $(TEST_DIR)/ft_out
		@$(TEST_DIR)/quicktest.out st | cat -A > $(TEST_DIR)/st_out
		@diff $(TEST_DIR)/ft_out $(TEST_DIR)/st_out > $(TEST_DIR)/diff || exit 0


# Relink
re:				fclean all

# Phony Targets don't produce a named target.
.PHONY:			fclean clean all re test quicktest