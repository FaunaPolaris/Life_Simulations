//    Any live cell with fewer than two live neighbors dies as if caused by underpopulation.
//    Any live cell with two or three live neighbors lives on to the next generation.
//    Any live cell with more than three live neighbors dies, as if by overpopulation.
//    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <stdio.h>
#include "../header/liblife.h"

int	ConwaysGameofLife(void)
{
	char	**grid;
	int	current;
	int	i = 0;

	grid = NULL;
	current = 1;
	grid = fp_rectangle_grid(grid, WIDTH, HEIGHT);
	if (!grid)
		return (1);
	fp_fill_grid(grid, WIDTH, HEIGHT, ' ');
	srand(time(NULL));
	while (i < HEIGHT * (WIDTH / 10))
	{
		int rand_row = rand() % HEIGHT;
		int rand_col = rand() % WIDTH;
		grid[rand_row][rand_col] = '*';
		i++;
	}
	fp_border_grid(grid, WIDTH, HEIGHT, 'x');
	while (current < ITERATIONS)
	{
		int	j = 0;
		while (j < HEIGHT)
		{
			printf("%s\n", grid[j]);
			j++;
		}
		Conway_rules(&grid, WIDTH, HEIGHT);
		current++;
		usleep(500 * 1000);
		if ((current + 2) != WIDTH * HEIGHT)
			system("clear");
	}
	free(grid);
	return (0);
}

void	Conway_rules(char ***grid, int width, int height)
{
	int	x;
	int	y;
	int	live_cells;

	live_cells = 0;
	y = 1;
	while (y < (height - 1))
	{
		x = 1;
		while (x < (width - 1))
		{
			live_cells = fp_chrd_grid(grid, x, y, '*');
			live_cells += fp_chrs_grid(grid, x, y, '*');
			if (live_cells == -1)
				break ;
			if (grid[0][y][x] == '*' && live_cells < 2)
				grid[0][y][x] = ' ';
			else if (grid[0][y][x] == '*' && live_cells > 3)
				grid[0][y][x] = ' ';
			else if (grid[0][y][x] == ' ' && live_cells == 3)
				grid[0][y][x] = '*';
			x++;
		}
		y++;
	}
}
