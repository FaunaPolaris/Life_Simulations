#include "liblife.h"

elements	*init_elements(int water, int earth, int air, int fire)
{
	elements	*output;

	output = (elements *)malloc(sizeof(elements));
	output->water = water;
	output->earth = earth;
	output->air = air;
	output->fire = fire;
	return (output);
}
