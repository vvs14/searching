/*
Given an array of n distinct integers sorted in ascending order, 
write a function that returns a Fixed Point in the array, if there is any Fixed Point present in array, else returns -1. 
Fixed Point in an array is an index i such that arr[i] is equal to i.
 Note that integers in array can be negative.
*/

#include "c_utilities.h"
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr)	(sizeof(arr)/sizeof(arr[0]))

//function to  find and return fixed point
int get_fixed_point(int *arr, int low, int high);
//Comparision function for qsort(), ascending order
int comp_int( const void *a, const void *b)	{	return *(int*)a - *(int*)b;	}
//Comparision function for qsort(), descending order
//int comp_int( const void *a, const void *b)	{	return *(int*)b - *(int*)a;	}

int main(int argc, char const *argv[])
{
	//int arr[]={-10, -5, 0, 3, 7};
	//int arr[]={0, 2, 5, 8, 17};
	int arr[]={-10, -5, 3, 4, 7, 9};
	int fixed = get_fixed_point(arr, 0, ARRAY_SIZE(arr)-1); 
	if (fixed!=-1)
		printf("Fixed point is : %d\n",fixed);
	else
		printf("No fixed point in array\n");
	return 0;
}//end main


int get_fixed_point(int *arr, int low, int high)
{
	int mid;
	while (low <=high)
	{
		mid = low + (high-low)/2;
		if (arr[mid]==mid)
			return mid;
		else  if (arr[mid] < mid)
			low = mid+1;
		else
			high = mid-1;
	}
	return -1;
}//end get_fixed_point