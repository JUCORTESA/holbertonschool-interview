#include "sandpiles.h"

/**
 * add - adds 2 grids
 * @grid1: 1st grid to add
 * @grid2: 2nd grid to add
 */
void add(int grid1[3][3], int grid2[3][3])
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			grid1[x][y] = grid1[x][y] + grid2[x][y];
		}
	}
}

/**
 * topple - topples a grid
 * @grid1: 1st grid to add
 * @sandpiles: aux grid
 */
void topple(int grid1[3][3], int sandpiles[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			sandpiles[x][y] = 0;
	}
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid1[x][y] >= 4)
			{
				sandpiles[x][y] -= 4;
				if (x + 1 < 3)
					sandpiles[x + 1][y]++;
				if (x - 1 >= 0)
					sandpiles[x - 1][y]++;
				if (y + 1 < 3)
					sandpiles[x][y + 1]++;
				if (y - 1 >= 0)
					sandpiles[x][y - 1]++;
			}
		}
	}
}
/**
 * print_sandpile - prints a grid
 * @grid: grid to print
 */
void print_sandpile(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * stable - checks if a sandpile is stable, < 4
 * @grid: grid to check
 * Return: 1 if true, 0 otherwise
 */
int stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}
/**
 * sandpiles_sum - adds 2 grids and print grid1
 * @grid1: 1st grid to add
 * @grid2: 2nd grid to add
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int sandpiles[3][3];

	add(grid1, grid2);
	while (stable(grid1) == 0)
	{
		printf("=\n");
		print_sandpile(grid1);
		topple(grid1, sandpiles);
		add(grid1, sandpiles);
	}
}
