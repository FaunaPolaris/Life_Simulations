#include "liblife.h"

int	G_simulation(void)
{
	organism	*world;
	int		i = 0;

	world = mould_list(WIDTH, HEIGHT);
	while (i < ITERATIONS)
	{
		usleep(10000 * 500);
		print_world(world);
		apply_patterns(world);
		printf("\n");
		i++;
	}
	free(world);
	return (0);
}

void	apply_patterns(organism *world)
{
	int i = 1;
	int j;

	while (i < HEIGHT - 1)
	{
		j = 1;
		while (j < WIDTH - 1)
		{
			if (world[i * WIDTH + j].ID < 3)
				mould_pattern(&world[i * WIDTH + j]);
			j++;
		}
	i++;
	}
}

void	print_world(organism *world)
{
	int i = 1;
	int j;

	while (i < HEIGHT - 1)
	{
		j = 1;
		while (j < WIDTH - 1)
		{
			identify(world[i * WIDTH + j].ID);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	identify(int ID)
{
	if (ID == 1)
		printf("\033[48;2;160;82;45;38;2;160;82;45m.\033[0m");
	if (ID == 2)
		printf("\033[48;2;139;69;19;38;2;139;69;19m.\033[0m");
	if (ID == 3)
		printf("\033[48;2;128;0;0;38;2;128;0;0m.\033[0m");
	if (ID == 4)
		printf("\033[44;34m.\033[0m");
}

