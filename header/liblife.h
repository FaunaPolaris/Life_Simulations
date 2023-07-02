#ifndef LIBLIFE_H
# define LIBLIFE_H

#include <stdlib.h>
#include <stdio.h>
#include "libft/header/libft.h"
#include <time.h>

/* MACROS*/

#define WIDTH 64
#define HEIGHT 24
#define ITERATIONS 10

#define INDEX(x, y) ((y) * WIDTH + (x))

#define north(x, y) INDEX(x, y - 1)
#define south(x, y) INDEX(x, y + 1)
#define west(x, y) INDEX(x - 1, y)
#define east(x, y) INDEX(x + 1, y)

#define north_west(x, y) INDEX(x - 1, y - 1)
#define north_east(x, y) INDEX(x + 1, y - 1)
#define south_west(x, y) INDEX(x - 1, y + 1)
#define south_east(x, y) INDEX(x + 1, y + 1)

/* Struct */

typedef struct elements {
	int	water;
	int	earth;
	int	air;
	int	fire;
}	elements;

typedef struct organism {
	elements	gene;
	elements	vitals;
	int		health[2];
	int		level;
	int		ID;
	int		index;
}	organism;
/* declarations */

/* Conway's game of Life */
int	ConwaysGameofLife();
void	Conway_rules(char ***, int width, int height);

/* Gaellus */
int	G_simulation();
organism	init_organism(int water, int earth, int arg, int fire, int ind);
void		free_organism(organism *to_free);

organism	init_mould(elements gene, int ind);
void		init_water_bed(organism donor);

organism	*mould_list(int width, int height);

void		mould_pattern(organism *mould);
void		free_moulds(organism *moulds);
void		apply_patterns(organism *world);
void		print_world(organism *world);
void		identify(int ID);
void		gaellus(organism *world, organism);

elements	randomize_gene(elements r_gene);
elements	init_elements(int water, int earth, int air, int fire);

#endif
