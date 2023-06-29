#include "lifes.h"

s_elements	init_elements(int water, int earth, int air, int fire)
{
	elements	output;

	output = (elements)malloc(sizeof(elements));
	if (!output)
		return (NULL);
	output.water = water;
	output.earth = earth;
	output.air = air;
	output.fire = fire;
	return (output);
}
