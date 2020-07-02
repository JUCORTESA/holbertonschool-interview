#include "slide_line.h"
/**
 * move - move the numbers to the specified direction
 * this function order the numbers inside the array,
 * putting all the numbers different from zero in the
 * direction side, 987600000 if left or  00009876 if right
 * @line: array of integers
 * @size: size of the array
 * @direction: direction to move, left or right
 */

void move(int *line, size_t size, int direction)
{
	int i, j;


	if (direction == 4)
	{
		for (i = 0; i < (int)size; i++)
		{
			if (line[i] != 0 && i != 0)
			{
				for (j = i; j > 0; j--)
				{
					if (line[j] != 0 && line[j - 1] == 0)
					{
						line[j - 1] = line[j];
						line[j] = 0;
					}
				}
			}
		}
	}
	else if (direction == 6)
	{
		for (i = ((int)size - 1); i >= 0; i--)
		{
			if (line[i] != 0 && i != ((int)size - 1))
			{
				for (j = i; j < (int)size - 1; j++)
				{
					if (line[j] != 0 && line[j + 1] == 0)
					{
						line[j + 1] = line[j];
						line[j] = 0;
					}
				}
			}
		}
	}

}

/**
 * join - add two numbers if equal, store the result
 * and replace the other element by 0
 * @line: array of integers
 * @size: size of the array
 * @direction: direction to move, left or right
 */

void join(int *line, size_t size, int direction)
{
	int i;


	if (direction == 4)
	{
		for (i = 0; i < (int)size - 1; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] += line[i + 1];
				line[i + 1] = 0;
			}
		}
	}
	else if (direction == 6)
	{
		for (i = ((int)size - 1); i > 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] += line[i - 1];
				line[i - 1] = 0;
			}
		}
	}

}

/**
 * slide_line - function that replicates the logic used in
 * 2048 game, but just applied in one line
 * @line: array of integers
 * @size: size of the array
 * @direction: direction to move, left or right
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	move(line, size, direction);
	join(line, size, direction);
	move(line, size, direction);
	return (1);
}