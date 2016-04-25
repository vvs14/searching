/*
Problem Statement: Given a sorted array with possible duplicate elements. 
Find number of occurrences of input ‘key’ in log N time.
This algorithm takes O(2*logn) time = O(logn).
See comparisions in output.
*/
#include "c_utilities.h"
#include <stdio.h>
#include <stdlib.h>

//wrapper function for get_occurances
int get_occurances_wrapper(int *arr, int low, int high, int key);
//function to find occurances of key using binary search
int get_occurances(int *arr, int low, int high, int key);
//function for comparision in qsort
int comp_int( const void *a, const void *b)	{	return *(int*)a - *(int*)b;	}

int main(int argc, char const *argv[])
{
	int n, r, key, occurances;
	int *arr=NULL;
	printf("Number of ints and Range resp. : \n");
	scanf("%d %d",&n, &r);
	printf("Key : \n");
	scanf("%d",&key);
	printf("Number of ints and Range resp. : %d and %d\n",n,r);
	printf("Key : %d\n",key );
	arr = generate_array(n, r);
	//print_array(arr, n);
	occurances = get_occurances_wrapper(arr, 0, n-1, key); 
	printf("occurances of key : %d is : %d\n",key, occurances );
	free(arr);
	return 0;
}

int get_occurances_wrapper(int *arr, int low, int high, int key)
{
	qsort(arr, high-low+1, sizeof(int), comp_int);
	//print_array(arr, high-low+1);
	return get_occurances(arr, low, high, key);
}//end get_occurances_wrapper

int get_occurances(int *arr, int low, int high, int key)
{
	int i,j;	//index variables;
	int start, mid, end;	//variable to hold indexes of first and last occurances of key
	i = low;
	j = high;
	int comparisions = 0;
	// finding first occurance,moving "i" towards first occurance of key
	while(i<j)
	{
		mid = i + (j-i)/2;		//to avoid overflow
		if (key <= arr[mid])	//if key is the left hlf of array, shrink array to left
			j=mid;
		else
			i = mid+1;
		//printf("Loop1:\nI :%d and j: %d\n",i,j );
		comparisions++;
	}
	//check if key is found
	if (arr[i]!=key)
		return 0;
	start =i;
	//finding last occurances, movie "j" towards last occurance of key
	//only resetting j, not i
	//Array only contains elements equal more greater than key
	j = high;
	while( i<j)
	{
		mid = i + (j-i)/2+1;	//biased towards right
		if (key < arr[mid])
			j= mid-1;			
		else
			i = mid;
		//printf("Loop 2:\nI :%d and j: %d\n",i,j );
		comparisions++;
	}
	end = j;
	printf("comparisions : %d\n",comparisions );
	return end-start+1;	
}//end get_occurances

