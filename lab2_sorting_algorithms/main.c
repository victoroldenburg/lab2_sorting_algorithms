#include "insertsort.h"
#include "load_file.h"
#include "mergesort.h"
#include <stdbool.h>
#include <stdio.h>
#include < stdlib.h >
#include <math.h>

int main()
{
	//################TASK1&TASK4 INSERT SORT######################################
	int arr[] = { 1,9,8,7,0,2,2,0 };

	int n_sort = sizeof(arr) / sizeof(arr[0]);

	int* sortedArray = insertionSort(arr,n_sort);

	printf("Task 1: Insertionsort\n");
	printArray(sortedArray,n_sort);
	printf("\n\n");
	

	////################TASK2&TASK4 MERGE SORT######################################
	int A[] = { 1,9,8,7,0,2,2,0 };

	int n_merge = sizeof(A) / sizeof(A[0]);

	int p = 0;
	int r = n_merge - 1;

	MergeSort(A, p, r);
	
	printf("Task 2: Merge Sort \n");
	printArray(A, n_merge);
	printf("\n\n");
	

	//################TASK5 LOAD FILES#######################################
	char sortingProblem[] = { "../sorting_problems/test-100-1-problem" };
	char sortingSolution[] = { "../sorting_problems/test-100-1-solution" };
	int* problemArr = load_file(sortingProblem);
	int* solutionArr = load_file(sortingSolution);

	int n = problemArr[0]+1;

	printf("Task 5: Verify implemented sort algorithms with load files\n\n");

	printf("Default data\n");
	printArray(problemArr, n);

	int* sortedArray_loadf = insertionSort_loadf(problemArr, n);

	printf("Sorted array\n");
	printArray(sortedArray_loadf, n);

	printf("The correct solution\n");
	printArray(solutionArr, n);

	return 0;
}