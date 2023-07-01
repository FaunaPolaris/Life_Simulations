/*
moulds with 8 > water will become a water bed;
moulds with height = 1 and 8 > earth will become leaf beds;
moulds with height > 1 and 10 earth will become corroded;
moulds with earth * 2 mould neighbors will gain + 1 height;
*/

#include "lifes.h"

organism	init_mould(elements gene, int posix[])
{
	organism	mould;

	mould = init_organism(gene.water, gene.earth, gene.air, gene.fire, posix);
	if (!mould)
		return (NULL);
	mould.ID = 1;
	mould.x_y[0] = posix[0];
	mould.x_y[1] = posix[1];
	return (mould);
}

organism	*mould_list(int width, int height)
{
	organism	*moulds;
	int			i;
	int			j;
	int			posix[2];
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
			posix[0] = j;
			posix[1] = i;
			gene = randomize_gene(gene);
			moulds[i * width + j] = init_mould(gene, posix);
			j++;
		}
		i++;
	}
	return (moulds);
}

void	mould_pattern(organism *mould)
{
	if (mould->gene->water % 2 = 0 && mould->gene->earth % 2 == 0)
		mould = init_water_bed(mould);
}

void	free_moulds(organism *moulds)
{
	int	i;

	i = 0;
	while (moulds[i].ID)
	{
		free_organism(moulds[i]);
		i++;
	}
	free(moulds);
}
