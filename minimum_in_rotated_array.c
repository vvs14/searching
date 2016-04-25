/*
Problem Statement: Given a sorted array of distinct elements, and the array is rotated at an unknown position. 
Find minimum element in the array.
No input as elements must be distinct and "rand()" may generate duplicates.
Algorithm tested on Array in program only.
*/
#include "c_utilities.h"
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr)	(sizeof(arr)/sizeof(arr[0])) 

//function to find minimum element in Rotated sorted array
int get_min(int *arr, int low, int high);

int main(void)
{
	//int arr[] = {14,15,1,3,4,5,6,7,8,9,10,11,12,13};
	//int arr[] = {3,4,5,6,7,8,9,10,11,12,13,14,1,2};
	//int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int arr[] = {20,21,22,23,1,2,3,4,5,6,7,8,9};
	int n = ARRAY_SIZE(arr);
	print_array(arr,n);
	printf("minimum element is : %d\n",get_min(arr,0,n-1)); 
 	return 0;
}//end main

int get_min(int *arr, int low, int high)
{
	int mid;
	while(low<high)
	{
		mid = low + (high-low)/2;	//to avoid overflow
		if (arr[mid] < arr[high])	//always try to compare mid with high as if only two elements, mid will be equal to low only. 
			high = mid;				//You will miss comparing high to mid.
		else
			low = mid+1;
	}
	return arr[low];
}//end get_min






















