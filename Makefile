NAME		=	lifes
CC		=	gcc
CFLAGS		=	-g3 -Wall -Wextra -Werror
LIBFT		=	header/lib

CONWAY		=	C_GOF/main.c

LIFE_LIB	=	header/
LIBFT		=	header/lib

YELLOW		=	\033[0;93m
SET_0		=	\033[0m
SET_0		=

all: libft $(NAME)

libft:
	@make -C $(LIBFT) data

$(NAME):
	@$(CC) $(CFLAGS) $(CONWAY) -I $(LIFE_LIB) -I $(LIBFT)/header -L$(LIBFT) -lft -o $(NAME)
	@echo "$(YELLOW)Compilation Succes$(SET_0)"
clean:
	@make -C $(LIBFT) fclean
	@rm -rf lifes

fclean: clean

re: fclean all

.PHONY: all libft clean fclean re
