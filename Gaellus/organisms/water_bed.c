#include "liblife.h"

void	turn_into_water_bed(organism *body, elements *NDNA)
{
	body->DNA = NDNA;
	body->ID = 4;
	body->age = 0;
	body->hunger = -1;
	body->health = 10 + (NDNA->earth % 10);
	body->move = NDNA->air % 10;
	body->action = NDNA->fire % 10;
}
