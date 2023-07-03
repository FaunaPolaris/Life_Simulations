#include "liblife.h"

int	same_type_neighbours(organism *world, int ID, int index)
{
	int	output = 0;

	if (world[NORTH(index)].ID == ID)
		output++;
	if (world[SOUTH(index)].ID == ID)
		output++;
	if (world[EAST(index)].ID == ID)
		output++;
	if (world[WEST(index)].ID == ID)
		output++;
	if (world[NORTH_EAST(index)].ID == ID)
		output++;
	if (world[NORTH_WEST(index)].ID == ID)
		output++;
	if (world[SOUTH_EAST(index)].ID == ID)
		output++;
	if (world[SOUTH_WEST(index)].ID == ID)
		output++;
	return (output);

}
