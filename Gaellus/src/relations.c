#include "liblife.h"

int	*check_sides(int index)
{
	int	*sides;

	sides = (int *)malloc(sizeof(int) * 8);
	if (sides == NULL)
		return NULL;
	sides[0] = (index % WIDTH == (WIDTH - 1) || index < WIDTH)
        	? 99
	        : g_world[NORTH_EAST(index)].ID;
	sides[1] = (index < WIDTH)
		? 99
	        : g_world[NORTH(index)].ID;
	sides[2] = (index % WIDTH == 0 || index < WIDTH)
        	? 99
	        : g_world[NORTH_WEST(index)].ID;
	sides[3] = (index % WIDTH == (WIDTH - 1))
        	? 99
	        : g_world[EAST(index)].ID;
	sides[4] = (index % WIDTH == 0)
        	? 99
	        : g_world[WEST(index)].ID;
    	sides[5] = (index % WIDTH == (WIDTH - 1) || index >= (HEIGHT - 1) * WIDTH)
       		? 99
		: g_world[SOUTH_EAST(index)].ID;
    	sides[6] = (index >= (HEIGHT - 1) * WIDTH)
        	? 99
        	: g_world[SOUTH(index)].ID;
	sides[7] = (index % WIDTH == 0 || index >= (HEIGHT - 1) * WIDTH)
		? 99
		: g_world[SOUTH_WEST(index)].ID;
	return sides;
}

int	look_for(int id, int *sides)
{
	int	i;
	int	output;

	i = 0;
	while (i < 8)
	{
		if (sides[i] == id)
			output++;
		i++;
	}
	return (output);
}

void	earth_food(int ind, int value)
{
	g_world[ind].DNA = NULL;
	g_world[ind].ID = 101;
	g_world[ind].hunger = value;
}

void	water_food(int ind, int value)
{
	g_world[ind].DNA = NULL;
	g_world[ind].ID = 102;
	g_world[ind].hunger = value;
}

void	air_food(int ind, int value)
{
	g_world[ind].DNA = NULL;
	g_world[ind].ID = 103;
	g_world[ind].hunger = value;
}

void	fire_food(int ind, int value)
{
	g_world[ind].DNA = NULL;
	g_world[ind].ID = 104;
	g_world[ind].hunger = value;
}
