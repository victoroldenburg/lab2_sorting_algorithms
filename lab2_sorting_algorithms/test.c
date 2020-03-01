#include "test.h"
#include "mergesort.h"
#include "insertsort.h"
#include "load_file.h"
#include <time.h>
#include <Windows.h>


void test_InsertionSort()
{
	//################TASK1&TASK4 INSERT SORT######################################
	int arr[] = { 1,9,8,7,0,2,2,0 };

	int n_sort = sizeof(arr) / sizeof(arr[0]);

	int* sortedArray = insertionSort(arr, n_sort);

	printf("Task 1: Insertionsort\n");
	printArray(sortedArray, n_sort);
	printf("\n\n");
}

void test_MergeSort()
{
	////################TASK2&TASK4 MERGE SORT######################################
	int A[] = { 1,9,8,7,0,2,2,0 };

	int n_merge = sizeof(A) / sizeof(A[0]);

	int p = 0;
	int r = n_merge - 1;

	MergeSort(A, p, r);

	printf("Task 2: Merge Sort \n");
	printArray(A, n_merge);
	printf("\n\n");
}

void test_InsertionSort_loadf()
{
	//################TASK5 LOAD FILES - INSERTION SORT#######################################
	char sortingProblem[] = { "../sorting_problems/test-100000-1-problem" };
	char sortingSolution[] = { "../sorting_problems/test-100000-1-solution" };
	int* problemArr = load_file(sortingProblem);
	int* solutionArr = load_file(sortingSolution);

	float time_spent = 0.0; //to store execution time

	int n = problemArr[0] + 1;

	printf("Task 5: Insertion Sort\n\n");

	printf("Default data\n");
	printArray(problemArr, n);

	clock_t start = clock();
	int* sortedArray_loadf = insertionSort_loadf(problemArr, n);
	clock_t end = clock();

	time_spent = ((float)(end - start)) / CLOCKS_PER_SEC;


	printf("Insertion Sort took %f seconds to execute \n", time_spent);

	printf("%f ", time_spent);

	printf("Sorted array\n");
	printArray(sortedArray_loadf, n);

	printf("The correct solution\n");
	printArray(solutionArr, n);

	printf("Default data\n");
	printArray(problemArr, n);

}

void test_MergeSort_loadf()
{
	//################TASK5 LOAD FILES - MERGE SORT#######################################
char sortingProblem[] = { "../sorting_problems/test-100000-1-problem" };
char sortingSolution[] = { "../sorting_problems/test-100000-1-solution" };
int* problemArr = load_file(sortingProblem);
int* solutionArr = load_file(sortingSolution);

int n = problemArr[0] + 1;
int p = 1;
int r = n - 1;

double time_spent = 0.0; //to store execution time


printf("Task 5: Merge Sort\n\n");

printf("Default data\n");
printArray(problemArr, n);

clock_t start = clock();
int* sortedArray_loadf = MergeSort_loadf(problemArr, p, r);
clock_t end = clock();

time_spent= ((float)(end - start)) / CLOCKS_PER_SEC;


printf("Merge Sort took %f seconds to execute \n", time_spent);


printf("Sorted array\n");
printArray(sortedArray_loadf, n);

printf("The correct solution\n");
printArray(solutionArr, n);

}

void printArray(int arr[], int n)
{


	for (int i = 0; i < n && i<=100; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n\n");
}

