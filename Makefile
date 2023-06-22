NAME		=	lifes
CC		=	gcc
CFLAGS		=	-g3 -Wall -Wextra -Werror
LIBFT		=	/header/lib

CONWAY		=	/C_GOF/main.c

all: libft $(NAME)

libft:
	make -C $(LIBFT) data

$(NAME):
	$(CC) $(CFLAGS) $(CONWAY) -L$(LIBFT) -lft -o $(NAME)

.PHONY: all libft
