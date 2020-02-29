#include "insertsort.h"
#include "load_file.h"
#include "mergesort.h"
#include "test.h"
#include <stdbool.h>
#include <stdio.h>
#include < stdlib.h >
#include <math.h>

int main()
{
	//#######START OF TEST - LAB2#######

	test_InsertionSort();

	test_MergeSort();

	test_InsertionSort_loadf();

	test_MergeSort_loadf();

	return 0;

	//#######END OF TEST - LAB2########

}