#include "liblife.h"

organism	init_organism(int ind)
{
	organism	*new_organism;

	new_organism = (organism *)malloc(sizeof(organism));
	if (!new_organism)
	{
		printf("Error: malloc failed in init_organism\n");
		return (new_organism[0]);
	}
	new_organism->index = ind;
	new_organism->ID = 0;
	return (*new_organism);
}

elements        *custom_DNA(int water, int earth, int air, int fire)
{
        elements        *output;

        output = (elements *)malloc(sizeof(elements));
        output->water = water;
        output->earth = earth;
        output->air = air;
        output->fire = fire;
        return (output);
}

elements	*random_DNA(int dif)
{
	elements	*RDNA;
	time_t		rand1 = time(NULL);
	unsigned int	seed = rand1 * dif;
	RDNA = (elements *)malloc(sizeof(elements));
	if (!RDNA)
		return (NULL);
	srand(seed);
	RDNA->water = rand();
	RDNA->earth = rand();
	RDNA->air = rand();
	RDNA->fire = rand();
	return (RDNA);
}

void	mutate(elements *DNA)
{
	int	*gene;
	int	i;
	int	end = 2;
	int	index;
	int	value;

	gene = segment_gene(DNA);
	for (i = 0; i < end; i++) 
	{
		index = rand() % 15;
		value = rand() % 256;
		gene[index] = value;
	}
	DNA = form_DNA(gene);
	free(gene);
}
//	gene segmenting:

int	*segment_gene(elements *DNA)
{
	int	i;
	int	byte_counter;
	int	*gene;

	i = 0;
	byte_counter = 24;
	gene = (int *)malloc(sizeof(int) * 17);
	if (!gene)
		return (NULL);
	gene[16] = '\0';
	while (i < 4)
	{
		gene[i] = (DNA->water >> byte_counter) & 0xFF;
		byte_counter -= 8;
		i++;
	}
	byte_counter = 24;
	while (i < 8)
	{
		gene[i] = (DNA->earth >> byte_counter) & 0xFF;
		byte_counter -= 8;
		i++;
	}
	byte_counter = 24;
	while (i < 12)
	{
		gene[i] = (DNA->air >> byte_counter) & 0xFF;
		byte_counter -= 8;
		i++;
	}
	byte_counter = 24;
	while (i < 16)
	{
		gene[i] = (DNA->fire >> byte_counter) & 0xFF;
		byte_counter -= 8;
		i++;
	}
	return (gene);
}

elements	*form_DNA(int *gene)
{
	elements	*NDNA;
	int	Nwater = 0;
	int	Nearth = 0;
	int	Nair = 0;
	int	Nfire = 0;
	int	i = 0;
	int	E = 0;

	NDNA = (elements *)malloc(sizeof(elements));
	while (i < 4)
	{
		Nwater &= gene[i] >> E;
		i++;
		E += 8;
	}
	E = 0;
	while (i < 8)
	{
		Nearth &= gene[i] >> E;
		i++;
		E += 8;
	}
	E = 0;
	while (i < 12)
	{
		Nair &= gene[i] >> E;
		i++;
		E += 8;
	}
	E = 0;
	while (i < 16)
	{
		Nfire &= gene[i] >> E;
		i++;
		E += 8;
	}
	E = 0;
	NDNA->water = Nwater;
	NDNA->earth = Nearth;
	NDNA->air = Nair;
	NDNA->fire = Nfire;
	return (NDNA);
}
