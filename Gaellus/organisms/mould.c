#include "liblife.h"

void	init_mould(organism *body, elements *NDNA)
{
	mutate(NDNA);
	body->ID = 2;
	body->age = 0;
	body->DNA = NDNA;
	body->hunger = -1;
	body->health = 10 + (NDNA->earth % 10);
	body->move = NDNA->air % 10;
	body->action = NDNA->fire % 10;
}

void	mould_sprout(organism *body, elements *NDNA)
{
	mutate(NDNA);
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
	NDNA = g_world[ind].DNA;
	gene = segment_gene(NDNA);
	sides = check_sides(ind);
	if (!gene || !sides)
		return ;

	// kill sequence
	if ((g_world[ind].age == gene[0] && g_world[ind].ID < 3) 
			|| g_world[ind].health < 1)
	{
		earth_food(ind, 12);
		return ;
	}

	// passive regeneration
	if (gene[6] < 20)
		g_world[ind].health += look_for(1, sides);
	if (gene[6] < 120)
		g_world[ind].health += look_for(2, sides);
	if (gene[6] < 200)
		g_world[ind].health += look_for(3, sides);
	
	// seed sequence
	if (g_world[ind].ID == 2)
	{
		if (look_for(0, sides) > 3 
				|| look_for(1, sides) > 5)
		{
			if (hit(4, ind))
				return ;
		}
		if (gene[5] < gene[7] || gene[7] < 20)
		{
			grow_up(sides, 2, NDNA, 1, ind);
			grow_down(sides, 2, NDNA, 1, ind);
			grow_left(sides, 1, NDNA, 1, ind);
			grow_right(sides, 1, NDNA, 1, ind);
		}
		else if (gene[5] > 200)
		{
			grow_up(sides, 2, NDNA, 1, ind);
		}
		else if (gene[7] < 120)
		{
			grow_up(sides, 2, NDNA, 1, ind);
			grow_down (sides, 1, NDNA, 1, ind);
		}
		else if (look_for(1, sides) <= 2)
		{
			grow_left(sides, 1, NDNA, 1, ind);
			grow_right(sides, 1, NDNA, 1, ind);
		}
	}
	if (g_world[ind].ID == 3)
	{
		if (look_for(0, sides) > 1 
			|| look_for(1, sides) < 5)
		{
			if (hit(10, ind))
				return ;
		}
		if (gene[5] < gene[7] && gene[7] < 160)
		{
			grow_up(sides, 2, NDNA, 1, ind);
			grow_down(sides, 1, NDNA, 1, ind);
		}
		else if (gene[5] > 200)
		{
			grow_up(sides, 2, NDNA, 3, ind);
		}
		else if (gene[7] < 120)
		{
			grow_left(sides, 1, NDNA, 2, ind);
			grow_right(sides, 2, NDNA, 2, ind);
		}
	}

	// growth sequence
	
	if (g_world[ind].ID == 2)
	{
		if ((gene[7] < gene[8] && gene[7] > 80)
				|| look_for(2, sides) > 5 
				|| look_for(3, sides) > 2)
			g_world[ind].ID = 3;
		else if (g_world[ind].age > 150)
			earth_food(ind, 20);

	}
}
