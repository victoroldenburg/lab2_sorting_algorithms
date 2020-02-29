#include "insertsort.h"
#include <stdbool.h>
#include <stdio.h>
#include < stdlib.h >
#include <math.h>
#include "insertsort.h"

int* insertionSort(int arr[],int n)
{

	int key = 0;
	int i = 0;

	for (int j = 1; j < n; j++)
	{
		key = arr[j];
		//Insert A[j] into sorted sequence A[1...j-1]
		i = j - 1;

		while (i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
	return arr;
}

int* insertionSort_loadf(int arr[], int n)
{
	int key = 0;
	int i = 0;

	for (int j = 1; j < n; j++)
	{
		key = arr[j];
		//Insert A[j] into sorted sequence A[1...j-1]
		i = j - 1;

		while (i >= 1 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
	return arr;
}


void printArray(int arr[], int n)
{


	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n\n");
}
