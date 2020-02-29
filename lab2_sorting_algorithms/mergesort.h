#pragma once
#include <stdbool.h>
#include <stdio.h>
#include < stdlib.h >
#include <math.h>

void Merge(int* A, int p, int q, int r);

void MergeSort(int* A, int p, int r);

int* Merge_loadf(int* A, int p, int q, int r);

int* MergeSort_loadf(int* A, int p, int r);

