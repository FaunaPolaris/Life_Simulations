#include "liblife.h"

organism	init_organism(int water, int earth, int air, int fire,
	       	int ind)
{
	organism	*new_organism;
	elements	*new_gene;
	elements	*new_vitals;

	new_organism = (organism *)malloc(sizeof(organism));
	if (!new_organism)
	{
		printf("Error: malloc failed in init_organism\n");
		return (new_organism[0]);
	}
	new_gene = init_elements(water, earth, air, fire);
	new_vitals = init_elements(water / 2, earth / 2, air / 2, fire / 2);
	new_organism->gene = *new_gene;
	new_organism->vitals = *new_vitals;
	new_organism->level = water + earth + air + (fire * 2);
	new_organism->index = ind;
	new_organism->health[1] = ((earth + water) / 2) + fire;
	free(new_gene);
	free(new_vitals);
	return (new_organism[0]);
}

elements	*randomize_gene(void)
{
	elements	*r_gene;

	r_gene = (elements *)malloc(sizeof(elements));
	r_gene->water = rand() % 10 * 2;
	r_gene->earth = rand() % 10 * 2;
	r_gene->air = rand() % 10 * 2;
	r_gene->fire = rand() % 10 * 2;
	return (r_gene);
}
