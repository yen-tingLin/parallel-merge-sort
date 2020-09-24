#include <stdio.h>



void test_array_is_sorted(int* arr, int size) {
	for(int i = 0; i < size-1; i++) {
		if(arr[i] > arr[i+1]) {
			printf("Error : array is NOT well-sorted at index %d and %d\n", i, i+1);
			return;
		}	
	}
	printf("array is well-sorted\n");	
}	
