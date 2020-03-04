#include "test.h"
#include "mergesort.h"
#include "insertsort.h"
#include "load_file.h"
#include <time.h>
#include <Windows.h>
#include <stdio.h>

//Global variables - only change these values
int arr[] = { 1,9,9,8,0,1,1,0 }; //Swedish personal number
int n_size = sizeof(arr) / sizeof(arr[0]); //Size of the array
int* array = arr;

char sortingProblem[] = { "../sorting_problems/test-100000-2-problem" };
char sortingSolution[] = { "../sorting_problems/test-100000-2-solution" };

//################TASK1&TASK4 INSERT SORT######################################
void test_InsertionSort() {

	//Local variables
	int pers = 1; //So we know to sort personal number or problem array
	int* sortedArray = insertionSort(array, n_size, pers);

	//Printing result
	printf("Task 1 and 4: Insertion Sort\n");
	printPersonalnumber(sortedArray, n_size);
	printf("\n\n");
}

////################TASK2&TASK4 MERGE SORT######################################
void test_MergeSort() {

	//Local variables
	int p = 0;
	int r = n_size - 1;

	//Functions
	MergeSort(array, p, r);

	//Printing result
	printf("Task 2 and 4: Merge Sort \n");
	printPersonalnumber(array, n_size);
	printf("\n\n");
}

//################TASK5 LOAD FILES - INSERTION SORT#######################################
void test_InsertionSort_loadf() {

	//Local variabels
	int pers = 0;
	int* problemArr = load_file(sortingProblem);
	int* solutionArr = load_file(sortingSolution);
	//Offset arrary from printing the 0th element, i.e. how many values in the array
	int n = problemArr[0] + 1;

	//Reset running time
	float time_spent = 0.0;

	//Print problem array from file 
	printf("Task 5: Insertion Sort\n\n");
	printf("Default data\n");
	printArray(problemArr, n);

	//Calculate running time
	clock_t start = clock();
	int* sortedArray_loadf = insertionSort(problemArr, n, pers);
	clock_t end = clock();
	time_spent = ((float)(end - start)) / CLOCKS_PER_SEC;

	//Print sorted array
	printf("Insertion Sort took %f seconds to execute \n", time_spent);
	printf("Sorted array\n");
	printArray(sortedArray_loadf, n);

	//Print correct solution from file
	printf("The correct solution\n");
	printArray(solutionArr, n);
}

//################TASK5 LOAD FILES - MERGE SORT#######################################
void test_MergeSort_loadf() {

	//Locla variables
	int* problemArr = load_file(sortingProblem);
	int* solutionArr = load_file(sortingSolution);

	int n = problemArr[0] + 1;
	int p = 1;
	int r = n - 1;

	//Print problem array from file
	printf("Task 5: Merge Sort\n\n");
	printf("Default data\n");
	printArray(problemArr, n);

	//Calculate running time	
	double time_spent = 0.0; //Reset running time
	clock_t start = clock();
	int* sortedArray_loadf = MergeSort(problemArr, p, r);
	clock_t end = clock();
	time_spent = ((float)(end - start)) / CLOCKS_PER_SEC;

	//Print sorted array
	printf("Merge Sort took %f seconds to execute \n", time_spent);
	printf("Sorted array\n");
	printArray(sortedArray_loadf, n);

	//Print correct solution from file
	printf("The correct solution\n");
	printArray(solutionArr, n);
}

//Print array of in the case of a Swedish psersonal number
//i.e. print the whole array
void printPersonalnumber(int* array, int n) {
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}
	printf("\n\n");
}

//Print array except first element
//i.e. don't print how many elemets are in the array as a part of the array
void printArray(int array[], int n) {
	if (n >= 100) {
		printf("Only printing the first 100 values of %d.\n", n-1);
	}
	for (int i = 1; i < n && i <= 100; i++)
	{
		printf("%d ", array[i]);
	}
	printf("...");
	printf("\n\n");
}
