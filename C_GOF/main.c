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

	if (argc != 2)
	{
		printf("Usage: ./life [size] [iterations]\n");
		return (0);
	}
	if (atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 16)
	{
		printf("Size must be between 1 and 16\n");
		return (0);
	}
	if (atoi(argv[2]) < 1 || ft_atoi(argv[2]) > 100)
	{
		printf("Iterations must be between 1 and 100\n");
		return (0);
	}
	grid = fp_alloc_grid(grid), ft_atoi(argv[1][0]);
	fill_grid(grid, ft_atoi(argv[1][0], '-');
	for (i = 0; i < size; i++)
		prinf("%s\n", grid[i]);
}
