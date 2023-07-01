#include "lifes.h"

organism	init_organism(int water, int earth, int air, int fire,
	       	int *posix)
{
	organism	new_organism;
	elements	new_gene;
	elements	new_vitals;

	new_organism = (organism)malloc(sizeof(organism));
	if (!organism)
		return (NULL);
	new_gene = init_elements(water, earth, air, fire);
	new_vitals = init_elements(water / 2, earth / 2, air / 2, fire / 2);
	new_organism.gene = new_gene;
	new_organism.vitals = new_vitals;
	new_organism.level = water + earth + air + (fire * 2);
	new_organism.index = INDEX(posix[0], posix[1]);
	new_organism.health[1] = ((earth + water) / 2) + fire;
	return (organism);
}

organism	reproduce(organism parent1, organism parent2)
{
	organism	child;
	int	temp[4];
	int	posix[2];

	posix[0] = parent1.current[0] + 1;
	posix[1] = parent1.current[1] + 1;
	temp[0] = fp_islowest(parent1.water, parent2.water) - 1;
	temp[1] = fp_islowest(parent1.earth, parent2.earth) - 1;
	temp[2] = fp_ishighest(parent1.air, parent2.air) - 1;
	temp[3] = fp_islowest(temp[0], temp[1], temp[2]);
	child = init_organism(temp[0], temp[1], temp[2], temp[3], posix);
}

void	free_organism(organism *to_free)
{
	if (to_free)
	{
		free(to_free->gene);
		free(to_free->vitals);
		free(to_free->x_y);
		free(to_free->health);
		free(to_free);
	}
}
elements	randomize_gene(elements r_gene)
{
	if (r_gene)
		free(r_gene);
	r_gene.water = rand() % 10;
	r_gene.earth = rand() % 10;
	r_gene.air = rand() % 10;
	r_gene.fire() = rand() % 10;
	return (r_gene);
}
