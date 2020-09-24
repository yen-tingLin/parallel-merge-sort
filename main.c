#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "merge_sort.h"
#include "sequential_merge_sort.c"
#include "parallel_merge_sort.c"
#include "test.c"


int generate_random_number(int upper_limit, int lower_limit);
void initialize_array(int* arr, int upper_limit, int length);
void print_array(int* arr, int size);


int main(int argc, const char * argv[]) {
	const int length = 100000;
	const int upper_lim = 1000;
	int* arr = (int*)malloc(length * sizeof(int));

	
	initialize_array(arr, upper_lim, length);
	
	struct timeval start, end;
	double time_spend;
	
//	print_array(arr, length);
/*	
	gettimeofday(&start, NULL);
	sequential_merge_sort(arr, 0, length-1);	
	gettimeofday(&end, NULL);

	time_spend = 1000000 * (end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec);
	printf("sequential : %f sec\n", time_spend/1000000);	
*/	
	gettimeofday(&start, NULL);
	parallel_merge_sort(arr, 0, length-1);	
	gettimeofday(&end, NULL);
	
	time_spend = 1000000 * (end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec);
	printf("parallel : %f sec\n", time_spend/1000000);	
	
//	print_array(arr, length);

	
	test_array_is_sorted(arr, length);


	free(arr);	
	return 0;
}


void initialize_array(int* arr, int upper_limit, int length) 
{
	srand(time(NULL));
	
	for(int i = 0; i < length; i++) {
		arr[i] = rand() % upper_limit;
	}
}

void print_array(int* arr, int size) 
{
	for(int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");	
}


