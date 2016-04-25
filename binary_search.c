/* 
C implementation of Binary Search
Input : Randomly generated array of "n" integers within range 0 to "r-1" and key to find
output : Index of key in randomly generated array
Read "README.md" file to understand compilation and execution procedure
*/
#include <stdio.h>
#include <stdlib.h>		//for qsort(). Do "man -k sort" in terminal to know more about it.
#include "c_utilities.h"	// keep "c_utilities.h" and "c_utilities.c" in same dir

//Binary Search Function
int bin_search(int *arr, int low, int high, int key);
//wrapper for binary search
int bin_search_wrapper(int *arr, int low, int high, int key);
//comparision function for "qsort" 
//http://www.cplusplus.com/reference/cstdlib/qsort/
int comp_int(const void *a, const void *b)
{
	return (*(int *)a -  *(int *)b);
}//comp_int

int main(void)
{
	int n, r, key, index;
	int *arr=NULL;
	printf("Number of ints and Range resp. : \n");
	scanf("%d %d",&n, &r);
	printf("Key : \n");
	scanf("%d",&key);
	printf("Number of ints and Range resp. : %d and %d\n",n,r);
	printf("Key : %d\n",key );
	arr = generate_array(n, r);
	//print_array(arr, n);
	index = bin_search_wrapper(arr, 0, n-1, key); 
	if ( index != -1)
		printf("Index of key : %d is : %d \n",key,index);
	else
		printf("Key not found\n");
	free(arr);
	return 0;
}//main

int bin_search(int *arr, int low, int high, int key)
{
	if(low<=high)
	{
		int mid = low + (high - low)/2;	// to avoid overflow
		if (key == arr[mid])
			return mid;
		else  if ( key <arr[mid])
			return bin_search(arr, low, mid-1, key);
		else
			return bin_search(arr, mid+1, high, key);
	}
	return -1;
}//bin_search

int bin_search_wrapper(int *arr, int low, int high, int key)
{
	qsort(arr, high - low+1, sizeof(int), comp_int);		//Binary Search need Sorted Array
	printf("Sorted array : \n");
	print_array(arr, high-low+1);
	return bin_search(arr, low, high, key);
}//bin_search_wrapper