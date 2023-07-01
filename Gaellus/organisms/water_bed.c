organism	*init_water_bed(organism old)
{
	organism	water_bed;

	water_bed = init_organism(old.water, old.earth, old.fire, old.air, old.posix);
	if (water_bed == NULL)
		return (NULL);
	water_bed.ID = 2;
	water_bed.index = old.index;
	free_organism(old);
	return (&water_bed);
}
