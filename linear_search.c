/*
C program of Linear Search.
Input : Number of integers (n) range of numbers (r), key (key)
Output : Index of  key
*/
#include "c_utilities.h"
#include <stdlib.h>
#include <stdio.h>

//linear search function
int lin_search(int *arr, int n, int key);

int main(void)
{
	int n, r, key, index;
	int *arr;
	printf("Number of ints and Range resp. : \n");
	scanf("%d %d",&n, &r);
	printf("Key : \n");
	scanf("%d",&key);
	printf("Number of ints and Range resp. : %d and %d\n",n,r);
	arr = generate_array(n, r);
	print_array(arr, n);
	if ( (index = lin_search(arr, n, key)) != -1)
		printf("Index of key : %d is : %d \n",key,index);
	else
		printf("Key not found\n");
	free(arr);
	return 0;
}//main

int lin_search(int *arr, int n, int key)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(key==arr[i])
			return i;
	}
	return -1;
}//lin_search
