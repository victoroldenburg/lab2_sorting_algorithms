#include "Header.h"
#include <stdbool.h>
#include <stdio.h>

int main()
{
	//Implement s sorting algorithm with quadratic complexity - insertion sort

	int arr[] = { 2,3,5,6,7,8,6,4,5,6,7,3,4,6,5 };

	int n = sizeof(arr) / sizeof(arr[0]);

	int* sortedArray = insertionSort(arr,n);

	printArray(sortedArray,n);

	return 0;
}