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

void apply_patterns(void)
{
    int i, j;
    int indices[HEIGHT * WIDTH];
    int num_indices = 0;

    // Generate all indices within the grid
    for (int idx = WIDTH + 1; idx < ((HEIGHT - 1) * WIDTH - 1); idx++)
    {
        i = idx / WIDTH;
        j = idx % WIDTH;
        if (i > 0 && i < (HEIGHT - 1) && j > 0 && j < (WIDTH - 1))
        {
            indices[num_indices++] = idx;
        }
    }

    // Shuffle the indices randomly
    srand(time(NULL));
    for (int k = num_indices - 1; k > 0; k--)
    {
        int random_index = rand() % (k + 1);
        int temp = indices[k];
        indices[k] = indices[random_index];
        indices[random_index] = temp;
    }

    // Iterate through the shuffled indices
    for (int idx = 0; idx < num_indices; idx++)
    {
        int current_idx = indices[idx];
        if (g_world[current_idx].ID != 0 && g_world[current_idx].ID <= 3)
        {
            mould_pattern(current_idx);
        }
        if (g_world[current_idx].ID > 100)
        {
            food_pattern(current_idx);
        }
	usleep(500 * 5);
	print_world();
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
		printf("\033[48;2;69;75;27m \033[0m");
	if (ID == 1)
		printf("\033[48;2;160;82;45;38;2;160;82;45m.\033[0m");
	if (ID == 2)
		printf("\033[48;2;139;69;19;38;2;139;69;19m.\033[0m");
	if (ID == 3)
		printf("\033[48;2;128;0;0;38;2;128;0;0m.\033[0m");
	if (ID == 4)
		printf("\033[44;34m.\033[0m");
	if (ID == 101)
		printf("\033[38;2;160;82;45m@\033[0m");
}

