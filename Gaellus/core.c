#include "life.h"

int	G_simulation(void)
{
	organism	*world;
	int			i;
	static int	iter = 0;

	world = mould_list(WIDTH, HEIGHT);
	while (iter < ITERATIONS)
	{
		print_world(world);
		apply_patterns(iter, world);
		i++;
	}
	return (0);
}
void	apply_patterns(static int iter, organism *world)
{
	int i = 0;
	int j;

	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (world[i * WIDTH + j].ID == 1)
				mould_pattern(&world, world[i * WIDTH + j]);
			j++;
		}
		printf("\n");
	i++;
	}
}

void	print_world(organism *world)
{
	int i = 0;
	int j;

	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			identify(world[i * WIDTH + j].ID);
			j++;
		}
		printf("\n");
	i++;
	}
}
void	identify(int ID);
{
	if (ID == 1)
		printf("\033[48;2;160;82;45;38;2;160;82;45m.\033[0m");
	if (ID == 2)
		printf("\033[44;34m.\033[0m");
}

