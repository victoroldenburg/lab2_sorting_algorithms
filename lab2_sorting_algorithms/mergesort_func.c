#include "mergesort.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Merge and Merge Sort - refer to pesudeo code in course book
int* Merge(int* A, int p, int q, int r) {
	const int n1 = q - p + 1;
	const int n2 = r - q;

	int* L = (int*)calloc(n1 + 8, sizeof(int));//Works, compensation for memory bits of 8. Warnings are compiler-dependent
	int* R = (int*)calloc(n2 + 8, sizeof(int));

	if (R != 0 && L != 0) {
		for (int i = 1; i <= n1; i++) {
			L[i] = A[p + i - 1];
		}
		for (int j = 1; j <= n2; j++) {
			R[j] = A[q + j];
		}

		//Sentinel
		L[n1 + 1] = INT_MAX;
		R[n2 + 1] = INT_MAX;

		int i = 1;
		int j = 1;

		for (int k = p; k <= r; k++){
			if (L[i] <= R[j]){
				A[k] = L[i];
				i++;
			}
			else{
				A[k] = R[j];
				j++;
			}
		}
		free(L);
		free(R);
	}
	return 0;
}

int* MergeSort(int* A, int p, int r) {
	if (p < r) {
		double qD = floor((p + r) / 2);
		int q = (int)qD;

		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
	return A;
}