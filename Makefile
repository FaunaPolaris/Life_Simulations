CC              =       gcc
CFLAGS          =       -g3 -Wall -Wextra -Werror

LIBLIFE         =       liblife.a
LIBFT           =       header/libft

SRC_CONWAY      =       core.c
SRC_GAELLUS     =       core.c element_struct.c genetics.c
SRC_ORGANISMS   =       mould.c water_bed.c

SRC_ALL         =       $(addprefix C_GOF/,$(SRC_CONWAY))
SRC_ALL         +=      $(addprefix Gaellus/src/,$(SRC_GAELLUS))
SRC_ALL         +=      $(addprefix Gaellus/organisms/,$(SRC_ORGANISMS))

YELLOW          =       \033[0;93m
SET_0           =       \033[0m
BOLD            =       \033[1m

NAME            =       Simulations

all: $(NAME)

$(NAME): ft
	@$(CC) $(CFLAGS) main.c $(SRC_ALL) -o $(NAME) -L $(LIBFT) -lft -I header
	@echo "$(YELLOW)$(BOLD)$(NAME) compiled, 'c' for conway; 'g' for gaellus$(SET_0)"

ft:
	@make -C $(LIBFT)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(NAME)
	@echo "$(YELLOW)$(BOLD)$(NAME) cleaned$(SET_0)"

fclean: clean
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all ft life clean fclean re
