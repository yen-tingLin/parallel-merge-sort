#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include "merge_sort.h"



typedef struct {
	int* arr;
	int left;
	int right;
} thread_data; 	

int thread_cnt = 0;
pthread_mutex_t mutex;


void* thread_merge_sort(void* arg) 
{	
	pthread_mutex_lock(&mutex);
	thread_cnt++;
	pthread_mutex_unlock(&mutex);	
	
	int* arr = ((thread_data*) arg)->arr;	
	int left = ((thread_data*) arg)->left;
	int right = ((thread_data*) arg)->right;
	
	
	if(left == right) pthread_exit(NULL);

	// keep number of thread == 2
	if(thread_cnt > 2) {
		sequential_merge_sort(arr, left, right);
		
		pthread_mutex_lock(&mutex);
		thread_cnt--;
		pthread_mutex_unlock(&mutex);
		
		pthread_exit(NULL);
		
	} else {		
		int mid = (left + right) / 2;
		
		thread_data* data_for_thread_1 = (thread_data*)malloc(sizeof(thread_data));
		data_for_thread_1->arr = arr;
		data_for_thread_1->left = left;
		data_for_thread_1->right = mid;
		
		thread_data* data_for_thread_2 = (thread_data*)malloc(sizeof(thread_data));
		data_for_thread_2->arr = arr;
		data_for_thread_2->left = mid+1;
		data_for_thread_2->right = right;
		
		pthread_t thread_1, thread_2;
		assert(!pthread_create(&thread_1, NULL, thread_merge_sort, (void*)data_for_thread_1));
		assert(!pthread_create(&thread_2, NULL, thread_merge_sort, (void*)data_for_thread_2));
		
		pthread_join(thread_1, NULL);
		pthread_join(thread_2, NULL);
		

		merge(arr, left, mid, right);
	
		
		pthread_exit(NULL);		 
	}	 
	
}

void parallel_merge_sort(int* arr, int left, int right) 
{
	pthread_mutex_init(&mutex, NULL);

	int mid = (left + right) / 2;
	
	thread_data* data_for_thread_1 = (thread_data*)malloc(sizeof(thread_data));
	data_for_thread_1->arr = arr;
	data_for_thread_1->left = left;
	data_for_thread_1->right = mid;
	
	thread_data* data_for_thread_2 = (thread_data*)malloc(sizeof(thread_data));
	data_for_thread_2->arr = arr;
	data_for_thread_2->left = mid+1;
	data_for_thread_2->right = right;
	
	pthread_t thread_1, thread_2;
	// pthread_create() return 0 when calls complete successfully 
	assert(!pthread_create(&thread_1, NULL, thread_merge_sort, (void*)data_for_thread_1));
	assert(!pthread_create(&thread_2, NULL, thread_merge_sort, (void*)data_for_thread_2));
	
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);		
	
	merge(arr, left, mid, right);

	
	pthread_mutex_destroy(&mutex);	
	
	free(data_for_thread_1);
	free(data_for_thread_2);
}
