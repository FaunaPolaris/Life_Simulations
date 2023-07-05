#include "liblife.h"

organism	*g_world;

int	G_simulation(void)
{
	int		i = 0;

	world_list(WIDTH, HEIGHT);
	if (!g_world)
		return (0);
	while (i < ITERATIONS)
	{
		usleep(1000 * 500);
		print_world();
		apply_patterns();
		i++;
	}
	free(g_world);
	return (0);
}

void	world_list(int width, int height)
{
	int	i = 0;

	g_world = (organism *)malloc(sizeof(organism) * (width * height));
	if (!g_world)
		return ;
	while (i < width * height)
	{
		g_world[i] = init_organism(i);
		i++;
	}
	abiogenesis();
}

void	abiogenesis(void)
{
	int count = 0;
	int max_index = (HEIGHT - 2) * (WIDTH - 2);

	while (count < STARTING_MOULD)
	{
		int index = rand() % max_index + 1;
        	if (g_world[index].ID == 0)
		{
			usleep(1000 * 500);
			elements *RDNA = random_DNA();
			init_mould(&g_world[index], RDNA);
		}
        	count++;
	}
}

void	apply_patterns(void)
{
	int i, j;

	for (int idx = WIDTH + 1; idx < ((HEIGHT - 1) * WIDTH - 1); idx++)
	{
		i = idx / WIDTH;
		j = idx % WIDTH;
		if (i > 0 && i < (HEIGHT - 1) && j > 0 && j < (WIDTH - 1))
		{
			if (g_world[idx].ID != 0 && g_world[idx].ID <= 3)
				mould_pattern(idx);
		}
	}

}

void	print_world(void)
{
	int i, j;

	for (int idx = WIDTH + 1; idx < ((HEIGHT - 1) * WIDTH - 1); idx++)
	{
		i = idx / WIDTH;
		j = idx % WIDTH;
		if (i > 0 && i < (HEIGHT - 1) && j > 0 && j < (WIDTH - 1))
		{
			identify(g_world[idx].ID);
			if (j == (WIDTH - 2))
				printf("\n");
		}
	}
}

void	identify(int ID)
{
	if (ID == 0)
		printf(" ");
	if (ID == 1)
		printf("\033[48;2;160;82;45;38;2;160;82;45m.\033[0m");
	if (ID == 2)
		printf("\033[48;2;139;69;19;38;2;139;69;19m.\033[0m");
	if (ID == 3)
		printf("\033[48;2;128;0;0;38;2;128;0;0m.\033[0m");
	if (ID == 4)
		printf("\033[44;34m.\033[0m");
}

