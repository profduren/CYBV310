/*****************************************************
 * Demonstration for week 2
 * Author:  Michael J Duren
 * Demonstrating the use of libraries
******************************************************/
#include <stdio.h>

void PrintDN();

int main()
{
	int nextInteger;
	int factorial;
	int value = 5;
	
	factorial = value;
	for (nextInteger = value - 1; nextInteger > 0; --nextInteger)
	{
		factorial = factorial * nextInteger;
	}

	printf("%d\n", factorial);

	PrintDN();

	return 0;
}