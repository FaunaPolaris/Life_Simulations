#ifndef LIBLIFE_H
# define LIBLIFE_H

#include <stdlib.h>
#include <stdio.h>
#include "libft/header/libft.h"
#include <time.h>

/* MACROS*/

#define WIDTH 128
#define HEIGHT 128
#define ITERATIONS 20
#define STARTING_MOULD 16

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
	elements	*DNA;
	int		hunger;
	int		health;
	int		move;
	int		action;
	int		age;
	int		ID;
	int		index;
}	organism;

extern organism *g_world;

/* declarations */

/* Conway's game of Life */
int	ConwaysGameofLife();
void	Conway_rules(char ***, int width, int height);

/* Gaellus */
//	organisms
//		mould:
void	init_mould(organism *, elements *NDNA);
void	mould_pattern(int ind);

//		water_bed:
void	turn_into_water_bed(organism *, elements *NDNA);

//	genetics
organism	init_organism(int ind);
elements	*custom_DNA(int water, int earth, int air, int fire);
elements	*random_DNA(void);
elements	*mutate(elements DNA);

int	*segment_gene(elements *DNA);
elements	*form_DNA(int *gene);

//	core
int	G_simulation(void);

void	free_world(void *);
void	world_list(int width, int height);
void	abiogenesis(void);
void	apply_patterns(void);
void	print_world(void);
void	identify(int ID);

//	relations
int	*check_sides(int index);
int	look_for(int ID, int *sides);
void	earth_food(int ind, int value);
void	water_food(int ind, int value);
void	air_food(int ind, int value);
void	fire_food(int ind, int value);

#endif
