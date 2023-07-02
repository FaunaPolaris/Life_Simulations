#include "liblife.h"

organism	init_organism(int water, int earth, int air, int fire,
	       	int ind)
{
	organism	*new_organism;
	elements	new_gene;
	elements	new_vitals;

	new_organism = (organism *)malloc(sizeof(organism));
	if (!new_organism)
	{
		printf("Error: malloc failed in init_organism\n");
		return (new_organism[0]);
	}
	new_gene = init_elements(water, earth, air, fire);
	new_vitals = init_elements(water / 2, earth / 2, air / 2, fire / 2);
	new_organism->gene = new_gene;
	new_organism->vitals = new_vitals;
	new_organism->level = water + earth + air + (fire * 2);
	new_organism->index = ind;
	new_organism->health[1] = ((earth + water) / 2) + fire;
	return (new_organism[0]);
}

void	free_organism(organism *to_free)
{
	if (to_free)
		free(to_free);
}

elements	randomize_gene(elements r_gene)
{
	r_gene.water = rand() % 10;
	r_gene.earth = rand() % 10;
	r_gene.air = rand() % 10;
	r_gene.fire = rand() % 10;
	return (r_gene);
}
