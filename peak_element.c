/*
@author : Vivek Vikram Singh
@date : 10.03.16

Given an array of integers. Find a peak element in it.
An array element is peak if it is NOT smaller than its neighbors. 
For corner elements, we need to consider only one neighbor. 
For example, for input array {5, 10, 20, 15}, 20 is the only peak element. 
For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. 
Note that we need to return any one peak element.
*/
#include "c_utilities.h"
#include <stdio.h>
#include <stdlib.h>

//Function to find and return peak element
int get_peak(int *arr, int low, int high);
//comparision function for qsort,ascending order
int comp_int( const void *a, const void *b)	{	return *(int*)a - *(int*)b;	}
////comparision function for qsort,descending order
//int comp_int( const void *a, const void *b)	{	return *(int*)b - *(int*)a;	}
int main(int argc, char const *argv[])
{
	int n, r, peak;
	int *arr=NULL;
	printf("Number of ints and Range resp. : \n");
	scanf("%d %d",&n, &r);
	printf("Number of ints and Range resp. : %d and %d\n",n,r);
	arr = generate_array(n, r);
	//TO SEE How does algo works on SORTED array, Uncomment below line to sort array
	//qsort(arr, n, sizeof(int), comp_int);
	print_array(arr, n);
	peak = get_peak(arr, 0, n-1);
	printf("Peak of array is : %d\n",peak);
	free(arr);
	//TO SEE how also works on Same elements, uncomment below 3 lines and comment all above lines in main
	//int arr_same[] = { 3,3,3,3,3,3,3,3,3,3};	//size=10
	//peak = get_peak(arr_same, 0, 9);
	//printf("Peak of array is : %d\n",peak);
	
	return 0;
}//end main

int get_peak(int *arr, int low, int high)
{
	int mid;
	while(low <high-1)
	{
		mid = low + (high-low)/2;
		if (arr[mid] <=arr[mid+1])
			low = mid;
		else
			high = mid;
	}
	return (arr[low] < arr[high])? arr[high]:arr[low];
}//end get_peak
