//Code for Conway's Game of Life
//     Any live cell with fewer than two live neighbors dies as if caused by underpopulation.
//    Any live cell with two or three live neighbors lives on to the next generation.
//    Any live cell with more than three live neighbors dies, as if by overpopulation.
//    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <stdio.h>
#include "life.h"

int	main(int argc, char **argv)
{
	char	**grid;
	int	current;
	int	size;
	int	i = 0;

	size = fp_atoi(argv[1]);
	grid = NULL;
	current = 1;
	if (argc != 3)
	{
		printf("Usage: ./lifes [size] [iterations]\n");
		return (1);
	}
	if (fp_atoi(argv[1]) < 16 || fp_atoi(argv[1]) > 64)
	{
		printf("Size must be between 16 and 64\n");
		return (1);
	}
	if (fp_atoi(argv[2]) < 500 || fp_atoi(argv[2]) > 1500)
	{
		printf("Iterations must be between 500 and 1500\n");
		return (1);
	}
	grid = fp_alloc_grid(grid, size);
	if (!grid)
		return (1);
	fp_fill_grid(grid, size, '-');
	srand(time(NULL));
	while (i < (size * 4))
	{
		int rand_row = rand() % size;
		int rand_col = rand() % size;
		grid[rand_row][rand_col] = '*';
		i++;
	}
	while (current < fp_atoi(argv[2]))
	{
		int	j = 0;
		while (j < size)
		{
			printf("%s\n", grid[j]);
			j++;
		}
		Conway_rules(&grid, size);
		current++;
		usleep(500 * 1000);
		if ((current + 2) != size)
			system("clear");
	}
	free(grid);
	return (0);
}

void	Conway_rules(char ***grid, int size)
{
	int	x;
	int	y;
	int	live_cells;

	live_cells = 0;
	y = 1;
	while (y < (size - 1))
	{
		x = 1;
		while (x < (size - 1))
		{
			live_cells = fp_chrd_grid(grid, x, y, '*');
			live_cells += fp_chrs_grid(grid, x, y, '*');
			if (live_cells == -1)
				break ;
			if (grid[0][y][x] == '*' && live_cells < 2)
				grid[0][y][x] = '-';
			else if (grid[0][y][x] == '*' && live_cells > 3)
				grid[0][y][x] = '-';
			else if (grid[0][y][x] == '-' && live_cells == 3)
				grid[0][y][x] = '*';
			x++;
		}
		y++;
	}
}
