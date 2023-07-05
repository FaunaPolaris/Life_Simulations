#include "liblife.h"

void	init_mould(organism *body, elements *NDNA)
{
	body->ID = 1;
	body->age = 0;
	body->DNA = NDNA;
	body->hunger = -1;
	body->health = 10 + (NDNA->earth % 10);
	body->move = NDNA->air % 10;
	body->action = NDNA->fire % 10;
}
void	mould_pattern(int ind)
{
	int	*sides;
	int	*gene;
	elements *NDNA;

	g_world[ind].age += 1;
	if ((g_world[ind].age == 5 && g_world[ind].ID == 1) || g_world[ind].health < 1)
	{
		earth_food(ind, 1);
		return ;
	}
	if (g_world[ind].age == 30 && g_world[ind].ID == 2)
	{
		earth_food(ind, 3);
		return ;
	}
	if (g_world[ind].age == 200 && g_world[ind].ID == 3)
	{
		earth_food(ind, 12);
		return ;
	}
	NDNA = g_world[ind].DNA;
	gene = segment_gene(NDNA);
	sides = check_sides(ind);
	if (sides == NULL)
		return ;
	if (g_world[ind].health > 10)
	{
		g_world[ind].health -= 5;
		if (gene[5] > 200 || gene[5] < gene[7])
			g_world[ind].ID = 2;
		else if (gene[7] > 150 || gene[8] < 50)
		{
			if (sides[6] == 0 && sides[5] == 0)
				init_mould(&g_world[SOUTH(ind)], NDNA);
			if (sides[1] == 0)
				init_mould(&g_world[NORTH(ind)], NDNA);
		}
		if (gene[5] > 180 && g_world[ind].ID == 2)
			g_world[ind].ID = 3;
		else if (gene[7] > 200 || gene[8] < 20)
		{
			if (sides[6] == 0)
			{
				if (sides[3] == 0)
					init_mould(&g_world[EAST(ind)], NDNA);
				if (sides[4] == 0)
					init_mould(&g_world[WEST(ind)], NDNA);
				if (sides[0] == 0)
					init_mould(&g_world[NORTH_EAST(ind)], NDNA);
				if (sides[7] == 0)
					init_mould(&g_world[SOUTH_WEST(ind)], NDNA);
			}
		}
	}
	if (g_world[ind].ID == 3)
	{
		if (look_for(0, sides) > 2 || ((look_for(1, sides) < 4) && (gene[7] > 150)))
		{
			if (sides[3] == 0)
				init_mould(&g_world[EAST(ind)], NDNA);
			if (sides[4] == 0)
				init_mould(&g_world[WEST(ind)], NDNA);
			if (sides[0] == 0)
				init_mould(&g_world[NORTH_EAST(ind)], NDNA);
			if (sides[7] == 0)
				init_mould(&g_world[SOUTH_WEST(ind)], NDNA);
		}
	}
	if (gene[2] > 150 && gene[3] > 150)
	{
		turn_into_water_bed(&g_world[ind], random_DNA());
	}
	free(gene);
	free(sides);
}
