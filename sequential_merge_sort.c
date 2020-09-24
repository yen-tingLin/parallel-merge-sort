#include <stdio.h>
#include <stdlib.h>



void merge(int* arr, int left, int mid, int right) {

    int left_len = mid - left + 1;
    int right_len = right - mid;


    int left_arr[left_len];
    for(int i = 0; i < left_len; i++) {
        left_arr[i] = arr[left+i];
    }

    int right_arr[right_len];
    for(int i = 0; i < right_len; i++) {
        right_arr[i] = arr[mid+1+i];
    } 


    int left_idx = 0;
    int right_idx = 0;
    int k = 0;
    
    while(left_idx < left_len && right_idx < right_len) {
		if(left_arr[left_idx] <= right_arr[right_idx]) {
			arr[left + k] = left_arr[left_idx];
			left_idx++;
		} else {
			arr[left + k] = right_arr[right_idx];
			right_idx++;
		}
		k++;		
	}
	
	while(left_idx < left_len) {
		arr[left + k] = left_arr[left_idx];
		left_idx++;
		k++;		
	}
	
	while(right_idx < right_len) {
		arr[left + k] = right_arr[right_idx];
		right_idx++;
		k++;		
	}	

}

void sequential_merge_sort(int* arr, int left, int right) {
    
    if(left == right) return;

    if(left < right) {
        int mid = (left + right) / 2;
        
        sequential_merge_sort(arr, left, mid);
        sequential_merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
        
    }

}

