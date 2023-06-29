/*
moulds with 8 > water will become a water bed;
moulds with height = 1 and 8 > earth will become leaf beds;
moulds with height > 1 and 10 earth will become corroded;
moulds with earth * 2 mould neighbors will gain + 1 height;
*/

#include "lifes.h"

organism	init_mould(elements gene, int posix)
{
	organism	mould;

	mould = init_organism(gene.water, gene.earth, gene.air, gene.fire, posix);
	mould.ID = 1;
	mould.name = "mould_1"
}
