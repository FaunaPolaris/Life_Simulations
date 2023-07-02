/*
moulds with 8 > water will become a water bed;
moulds with height = 1 and 8 > earth will become leaf beds;
moulds with height > 1 and 10 earth will become corroded;
moulds with earth * 2 mould neighbors will gain + 1 height;
*/

#include "liblife.h"

organism	init_mould(elements gene, int ind)
{
	organism	mould;

	mould = init_organism(gene.water, gene.earth, gene.air, gene.fire, ind);
	mould.ID = 1;
	mould.index = ind;
	return (mould);
}

organism	*mould_list(int width, int height)
{
	organism	*moulds;
	int			i;
	int			j;
	elements	gene;

	moulds = (organism *)malloc(sizeof(organism) * (width * height));
	if (!moulds)
		return (NULL);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			gene = randomize_gene(gene);
			moulds[i * width + j] = init_mould(gene, INDEX(j, i));
			j++;
		}
		i++;
	}
	return (moulds);
}

void	mould_pattern(organism *mould)
{
	if (mould->gene.water % 2 == 0 && mould->gene.earth % 2 == 0)
		mould->ID = 2;
}

void	free_moulds(organism *moulds)
{
	int	i;

	i = 0;
	while (moulds[i].ID)
	{
		free_organism(moulds);
		i++;
	}
	free(moulds);
}
