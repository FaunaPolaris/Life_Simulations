#ifndef LIBLIFE_H
# define LIBLIFE_H

#include <stdlib.h>
#include <stdio.h>
#include "libft/header/libft.h"
#include <time.h>

/* MACROS*/

#define WIDTH 16
#define HEIGHT 16
#define ITERATIONS 4

#define INDEX(x, y) ((y) * WIDTH + (x))

#define XPOS(x) ((x) / WIDTH)
#define YPOS(y) ((y) % HEIGHT)

#define NORTH(index) INDEX(XPOS(index), YPOS(index) - 1)
#define SOUTH(index) INDEX(XPOS(index), YPOS(index) + 1)
#define EAST(index) INDEX(XPOS(index) + 1, YPOS(index))
#define WEST(index) INDEX(XPOS(index) - 1, YPOS(index))

#define NORTH_EAST(index) INDEX(XPOS(index) + 1, YPOS(index) - 1)
#define NORTH_WEST(index) INDEX(XPOS(index) - 1, YPOS(index) - 1)
#define SOUTH_EAST(index) INDEX(XPOS(index) + 1, YPOS(index) + 1)
#define SOUTH_WEST(index) INDEX(XPOS(index) - 1, YPOS(index) + 1)

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
void		free_list(organism *world);

organism	init_mould(elements gene, int ind);
void		init_water_bed(organism donor);

organism	*mould_list(int width, int height);

void		mould_pattern(organism *mould);
void		free_moulds(organism *moulds);
void		apply_patterns(organism *world);
void		print_world(organism *world);
void		identify(int ID);
void		gaellus(organism *world, organism);

elements	*randomize_gene(void);
elements	*init_elements(int water, int earth, int air, int fire);

int		same_type_neighbours(organism *world, int ID, int index);
#endif
