#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int stable(int grid[3][3]);
void print_sandpile(int grid[3][3]);
void add(int grid1[3][3], int grid2[3][3]);
void topple(int grid1[3][3], int sandpiles[3][3]);
#endif /* SANDPILES_H*/
