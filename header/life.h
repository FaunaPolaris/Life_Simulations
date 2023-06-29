#ifndef LIFE_H
# define LIFE_H

#include <stdlib.h>
#include "libft.h"
#include <time.h>

/* MACROS*/

#define WIDTH 128
#define HEIGHT 32
#define ITERATIONS 1000

#define INDEX(x, y) ((y) * WIDTH + (x))

#define north(x, y) INDEX(x, y - 1)
#define south(x, y) INDEX(x, y + 1)
#define west(x, y) INDEX(x - 1, y)
#define east(x, y) INDEX(x + 1, y)

#define north_west(x, y) INDEX(x - 1, y - 1)
#define north_east(x, y) INDEX(x + 1, y - 1)
#define south_west(x, y) INDEX(x - 1, y + 1)
#define south_east(x, y) INDEX(x + 1, y + 1)

/* declarations */

/* Conway's game of Life */
void	Conway_rules(char ***, int width, int height);

/* Gaellus */

/* Struct */

typedef struct t_list {
	organism	*inhabitant;
	t_list	*next;
	t_list	*prev;
	int	index;
}	s_list;

typedef struct elements {
	int	water;
	int	earth;
	int	air;
	int	fire;
}	elements;

typedef struct organism {
	elements	gene;
	elements	vitals;
	int		x_y[2];
	int		health[2];
	int		level;
	int		ID;
	char	*name;
}	organism;

#endif
