#ifndef LIFE_H
# define LIFE_H

#include <stdlib.h>
#include "libft.h"
#include <time.h>

/* declarations */

/* Conway's game of Life */
void	Conway_rules(char ***, int size);

/* Gaellus */

/* Struct */

typedef struct elements {
	int	water;
	int	earth;
	int	air;
	int	fire;
}	elements

typedef struct organism {
	int		height;
	elements	gene;
	elements	vitals;
	int		x_y[2];
	int		health[2];
	int		level;
}	organism

#endif
