/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int* inside_wrapper(int** input, int starti, int startj, int endi, int endj, int * output, int k, int m, int n)
{
	if (starti < endi && startj < endj)
	{
		int i = starti, j = startj;
		for (j = startj; j < endj; j++, k++)
		{
			output[k] = input[starti][j];
		}
		starti++;
		for (i = starti; i < endi; i++, k++){
			output[k] = input[i][endj - 1];
		}
		endj--;
		if (starti < endi)
		{
			for (j = endj - 1; j >= startj; j--, k++)
			{
				output[k] = input[endi - 1][j];
			}
			endi--;
		}
		if (startj < endj)
		{
			for (i = endi - 1; i >= starti; i--, k++){
				output[k] = input[i][startj];
			}
			startj++;
		}
		return inside_wrapper(input, starti, startj, endi, endj, output, k, m, n);
	}
	return output;
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL)
		return NULL;
	if (rows <= 0 || columns <= 0)
		return NULL;
	int*output = (int*)malloc(sizeof(int)*rows*columns);
	return inside_wrapper(input_array, 0, 0, rows, columns, output, 0, rows, columns);
}
