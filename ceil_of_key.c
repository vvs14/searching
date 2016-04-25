/*
Problem Statement: Given an array of N distinct integers, 
find ceil value of input ‘key’. Say, A = {-1, 2, 3, 5, 6, 8, 9, 10} and key = 7, 
we should return 8 as outcome.
In our case, we will have array of numbers within range 0 to r-1. Error(floor value not found) will be denoted by -1.
*/
#include "c_utilities.h"
#include <stdio.h>
#include <stdlib.h>

//wrapper function
int wrapper_func(int *arr, int low, int high, int key);
//functio tom find ceil of key. Using iterative approach rather than Recusrive.
int find_ceil(int *arr, int low, int high, int key);
//Comparision function used in qsort()
int comp_int( const void *a, const void *b)	{	return *(int*)a - *(int*)b;	}

int main(int argc, char const *argv[])
{
	int n, r, key, ceil_val;
	int *arr=NULL;
	printf("Number of ints and Range resp. : \n");
	scanf("%d %d",&n, &r);
	printf("Key : \n");
	scanf("%d",&key);
	printf("Number of ints and Range resp. : %d and %d\n",n,r);
	printf("Key : %d\n",key );
	arr = generate_array(n, r);
	//print_array(arr, n);
	ceil_val = wrapper_func(arr, 0, n-1, key); 
	if ( ceil_val != -1)
		printf("Ceil value of key : %d is : %d \n",key,ceil_val);
	else
		printf("ceil value of Key not found\n");
	free(arr);
	return 0;
}//end main

int wrapper_func(int *arr, int low, int high, int key)
{
	//binary search need sorted array
	qsort(arr, high-low+1,sizeof(int), comp_int);
	print_array(arr, high-low+1);
	if (key > arr[high])	//==arr[n-1]
		return -1;		//error
	else
		return find_ceil(arr, low, high, key);
}//end wrapper_func

int find_ceil(int *arr, int low, int high, int key)
{
	int mid;
	while( low <high)	//at least three elements in array
	{
		mid = low + (high-low)/2;
		if (arr[mid] <=key)
			low = mid+1;
		else
			high = mid;
	}
	return arr[low];
}//end find_floor