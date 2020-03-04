#include "insertsort.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Insertion Sort - refer to pesudeo code in course book
int* insertionSort(int arr[], int n, int pers){
	int key = 0;
	int i = 0;

	for (int j = 1; j < n; j++){
		key = arr[j];
		//Insert A[j] into sorted sequence A[1...j-1]
		i = j - 1;

		if (pers != 1) {
			while (i >= 1 && arr[i] > key){
				arr[i + 1] = arr[i];
				i = i - 1;
			}
			arr[i + 1] = key;
		}
		else {
			while (i >= 0 && arr[i] > key){
				arr[i + 1] = arr[i];
				i = i - 1;
			}
			arr[i + 1] = key;
		}
	}
	return arr;
}


