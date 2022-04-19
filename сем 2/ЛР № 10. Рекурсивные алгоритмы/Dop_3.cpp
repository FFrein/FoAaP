#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
void swap(int* a, int* b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
void reverse(int* P, int m)
{
	int i = 0, j = m;
	while (i < j)
	{
		swap(&P[i], &P[j]);
		++i;
		--j;
	}
}
void try_all(int* P, int m)
{
	int i;
	if (m == 0)
	{
		for (i = 0; i < 5; ++i)
			printf("%d ", P[i]);
		printf("\n");
	}
	else
	{
		for (i = 0; i <= m; ++i)
		{
			try_all(P, m - 1);
			if (i < m)
			{
				swap(&P[i], &P[m]);
				reverse(P, m - 1);
			}
		}
	}
}
void main()
{
	int i;
	int P[5];
	for (i = 0; i < 5; ++i)
		P[i] = i + 1;
	try_all(P, 5 - 1);
}