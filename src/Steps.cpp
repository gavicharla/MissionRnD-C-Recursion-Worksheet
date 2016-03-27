/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"


int get_steps(int s)
{
	//as i tend to solve for every increment in step .. it is the same as fibonacci series ...
	//but here the series starts with 1,2,3,5,8,13..... so get_steps(n) means fib(n+1)
	if (s <= 0)
		return 0;
	if (s == 2)
		return 2;
	if (s == 1)
		return 1;
	
	return get_steps(s - 1) + get_steps(s - 2);
}
