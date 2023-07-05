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

void	dploriferate(int *sides, int ID, elements *NDNA, int quantity, int index)
{
	int	seeds = 0;

	if (sides[0] == 0 && seeds < quantity)
	{
		if (ID == 1)
			init_mould(&g_world[NORTH_EAST(index)], NDNA);
		seeds++;
	}
	if (sides[2] == 0 && seeds < quantity)
	{
		if (ID == 1)
			init_mould(&g_world[NORTH_WEST(index)], NDNA);
		seeds++;
	}
	if (sides[5] == 0 && seeds < quantity)
	{
		if (ID == 1)
			init_mould(&g_world[SOUTH_EAST(index)], NDNA);
		seeds++;
	}
	if (sides[7] == 0 && seeds < quantity)
	{
		if (ID == 1)
			init_mould(&g_world[SOUTH_WEST(index)], NDNA);
		seeds++;
	}
}

static void check_ID(int ID, int index, elements *NDNA)
{
	if (ID == 1)
		mould_sprout(&g_world[index], NDNA);
	if (ID == 2)
		init_mould(&g_world[index], NDNA);
}

void	grow_right(int *sides, int ID, elements *NDNA, int quantity, int index)
{
	int	seeds = 0;

	if (sides[3] == 0 && seeds < quantity)
	{
		check_ID(ID, EAST(index), NDNA);
		seeds++;
	}
	if (sides[0] == 0 && seeds < quantity)
	{
		check_ID(ID, NORTH_EAST(index), NDNA);
		seeds++;
	}
	if (sides[5] == 0 && seeds < quantity)
	{
		check_ID(ID, SOUTH_EAST(index), NDNA);
		seeds++;
	}
}

void	grow_left(int *sides, int ID, elements *NDNA, int quantity, int index)
{
	int	seeds = 0;

	if (sides[4] == 0 && seeds < quantity)
	{
		check_ID(ID, WEST(index), NDNA);
		seeds++;
	}
	if (sides[2] == 0 && seeds < quantity)
	{
		check_ID(ID, NORTH_WEST(index), NDNA);
		seeds++;
	}
	if (sides[7] == 0 && seeds < quantity)
	{
		check_ID(ID, SOUTH_WEST(index), NDNA);
		seeds++;
	}
}

void	grow_up(int *sides, int ID, elements *NDNA, int quantity, int index)
{
	int	seeds = 0;

	if (sides[1] == 0 && seeds < quantity)
	{
		check_ID(ID, NORTH(index), NDNA);
		seeds++;
	}
	if (sides[0] == 0 && seeds < quantity)
	{
		check_ID(ID, NORTH_EAST(index), NDNA);
		seeds++;
	}
	if (sides[2] == 0 && seeds < quantity)
	{
		check_ID(ID, NORTH_WEST(index), NDNA);
		seeds++;
	}
}

void	grow_down(int *sides, int ID, elements *NDNA, int quantity, int index)
{
	int	seeds = 0;

	if (sides[6] == 0 && seeds < quantity)
	{
		check_ID(ID, SOUTH(index), NDNA);
		seeds++;
	}
	if (sides[5] == 0 && seeds < quantity)
	{
		check_ID(ID, SOUTH_EAST(index), NDNA);
		seeds++;
	}
	if (sides[7] == 0 && seeds < quantity)
	{
		check_ID(ID, SOUTH_WEST(index), NDNA);
		seeds++;
	}
}

int	look_for(int id, int *sides)
{
	int	i;
	int	output;

	output = 0;
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

int	hit(int damage, int index)
{
	if (index < 0 || index > (WIDTH * HEIGHT))
		return (1);
	g_world[index].health -= damage;
	if (g_world[index].health <= 0)
	{
		kill(index);
		return (1);
	}
	return (0);
}

void	kill(int index)
{
	g_world[index].DNA = NULL;
	g_world[index].ID = 0;
}

void	nuke(int index)
{
	kill(NORTH(index));
	kill(NORTH_EAST(index));
	kill(EAST(index));
	kill(SOUTH_EAST(index));
	kill(SOUTH(index));
	kill(SOUTH_WEST(index));
	kill(WEST(index));
	kill(NORTH_WEST(index));
	kill(index);
}
