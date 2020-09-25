#ifndef _MERGESORT_H_
#define _MERGESORT_H_


/* sequential merge sort
 * @ arr : pointer to input array
 * @ left : index of the left border of array
 * @ right : index of the right border of array
 */
void sequential_merge_sort(int* arr, int left, int right);

/* parallel merge sort
 * @ arr : pointer to input array 
 * @ left : index of the left border of array
 * @ right : index of the right border of array
 */ 
void parallel_merge_sort(int* arr, int left, int right);

/* compare elements of two arrays and merge into an ordered array 
 * @ arr : pointer to original input array 
 * @ left : index of the left border of array
 * @ right : index of the left border of array
 * @ mid : index of the middle of above array
 */
void merge(int* arr, int left, int mid, int right);

/* test whether the input array is well-sorted after merge sort
 * @ arr : pointer to sorted array 
 * @ size : size of array
 */
void test_array_is_sorted(int* arr, int size);


#endif
