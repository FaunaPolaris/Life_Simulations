NAME		=	lifes
CC		=	gcc
CFLAGS		=	-g3 -Wall -Wextra -Werror

LIFE_LIB	=	header/
LIBFT		=	header/libft

YELLOW		=	\033[0;93m
SET_0		=	\033[0m
BOLD		=	\033[1m

all: $(NAME)

libft:
	@make -C $(LIBFT)

$(NAME): $(LIBFT)
	@$(CC) $(CFLAGS) -o lifes main.c -I $(LIFE_LIB) -I $(LIBFT)/header -L $(LIBFT) -lft -o $(NAME)
	@echo "$(YELLOW)$(BOLD)lifes$(SET_0) created/n usage:/n"
	@echo "./lifes [$(YELLOW)$(BOLD)conway$(SET_0)]"
	@echo "./lifes ]$(YELLOW)$(BOLD)gaellus$(SET_0)]"

clean:
	@make -C $(LIBFT) fclean
	@rm -rf lifes

fclean: clean

re: fclean all

.PHONY: all libft clean fclean re
