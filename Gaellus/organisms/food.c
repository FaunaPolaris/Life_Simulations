#include "liblife.h"

void	food_pattern(int ind)
{
	int	*sides = check_sides(ind);

	g_world[ind].hunger -= 1;
	if (g_world[ind].hunger < 1)
	{
		kill(ind);
		return ;
	}
	if (g_world[ind].ID == 101)
	{
		if (look_for(101, sides) >= 8)
		{
			nuke(ind);
			elements *RDNA = random_DNA();
			init_mould(&g_world[ind], RDNA);
		}
	}
}
