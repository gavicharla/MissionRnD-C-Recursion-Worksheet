/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
int wrapper_func(int*arr, int m, int n, int i, int j, int tari, int tarj)
{
	if (i == tari && tarj == j)
		return 1;
	int a, b, c, d;
	a = b = c = d = 0;
	arr[i*n + j] = -1;
	if (i - 1 >= 0)
		if (arr[(i - 1)*n + j] == 1)
			a = wrapper_func(arr, m, n, i - 1, j, tari, tarj);
	if (i + 1 < m)
		if (arr[(i + 1)*n + j] == 1)
			b = wrapper_func(arr, m, n, i + 1, j, tari, tarj);
	if (j - 1 >= 0)
		if (arr[(i)*n + j - 1] == 1)
			c = wrapper_func(arr, m, n, i, j - 1, tari, tarj);
	if (j + 1<n)
		if (arr[(i)*n + j + 1] == 1)
			d = wrapper_func(arr, m, n, i, j + 1, tari, tarj);

	arr[i*n + j] = 1;
	if (a || b || c || d)
		return 1;
	else
		return 0;

}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int temp;
	if (maze == NULL)
		return 0;
	if (x1 >= rows || x1 < 0 || x2 >= rows || x2 < 0 || y1 >= columns || y1 < 0 || y2 >= columns || y2 < 0)
		return 0;
	temp = maze[x1*columns + y1];
	maze[x1*columns + y1] = -1;
	int a, b, c, d;
	a = b = c = d = 0;
	if (x1 - 1 >= 0)
		if (maze[(x1 - 1)* columns + y1] == 1)
			a = wrapper_func(maze, rows, columns, x1 - 1, y1, x2, y2);
	if (x1 + 1<rows)
		if (maze[(x1 + 1)* columns + y1] == 1)
			b = wrapper_func(maze, rows, columns, x1 + 1, y1, x2, y2);
	if (y1 - 1 >= 0)
		if (maze[(x1)* columns + y1 - 1] == 1)
			c = wrapper_func(maze, rows, columns, x1, y1 - 1, x2, y2);
	if (y1 + 1 <columns)
		if (maze[(x1)* columns + y1 + 1] == 1)
			d = wrapper_func(maze, rows, columns, x1, y1 + 1, x2, y2);
	maze[x1*columns + y1] = temp;
	if (a || b || c || d)
		return 1;
	else
		return 0;
}
