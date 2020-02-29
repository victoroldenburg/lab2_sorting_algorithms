#include "mergesort.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h >
#include <math.h>

void Merge(int* A, int p, int q, int r)
{

	int n1 = q - p + 1;
	int n2 = r - q;


	int* L = malloc((n1 + 1)  * sizeof(int));
	int* R = malloc((n2 + 1) * sizeof(int));


		for (int i = 1; i <= n1; i++)
		{
			L[i] = A[p + i - 1];
		}



		for (int j = 1; j <= n2; j++)
		{
			R[j] = A[q+j];
		}

		L[n1+1] = INT_MAX;
		R[n2+1] = INT_MAX;


		int i = 1;
		int j = 1;

		for (int k = p; k <= r ; k++)
		{

				if (L[i] <= R[j]) 
				{
					A[k] = L[i];
					i++;
				}
				else
				{
					A[k] = R[j];
					j++;
				}
		}
}


void MergeSort(int* A, int p, int r)
{
	if (p<r)
	{
		double qD = floor((p + r) / 2);
		int q = (int)qD;

		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);

	}
}


int* Merge_loadf(int* A, int p, int q, int r)
{

	int n1 = q - p + 1;
	int n2 = r - q;



	int* L = malloc((n1 + 1) * sizeof(int));
	int* R = malloc((n2 + 1) * sizeof(int));




	for (int i = 1; i <= n1; i++)
	{
		L[i] = A[p + i - 1];
	}



	for (int j = 1; j <= n2; j++)
	{
		R[j] = A[q + j];
	}

	
	if (R != 0 && L!=0)
	{
		L[n1 + 1] = INT_MAX;
		R[n2 + 1] = INT_MAX;

	}


	int i = 1;
	int j = 1;

	for (int k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
	return 0;
}


int* MergeSort_loadf(int* A, int p, int r)
{
	if (p < r)
	{
		double qD = floor((p + r) / 2);
		int q = (int)qD;

		MergeSort_loadf(A, p, q);
		MergeSort_loadf(A, q + 1, r);
		Merge_loadf(A, p, q, r);

	}
	return A;
}