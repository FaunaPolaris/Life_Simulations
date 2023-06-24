#ifndef LIFE_H
# define LIFE_H

#include <stdlib.h>
#include "libft.h"
#include <time.h>

/* declarations */

/* Conway's game of Life */
void	Conway_rules(char ***, int size);
int	check_diagonals(char ***, int x, int y);
int	check_sides(char ***, int x, int y);

#endif
