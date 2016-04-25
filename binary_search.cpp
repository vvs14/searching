/*
Binary Search implementation using Vector in C++
Input : number of elements, range r, and key within 0 to r-1
output : index of key in randomly generated vector
read "README.md" for compilation and execution notes
*/
#include "cpp_utilities.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//binary search wrapper
int bin_search_wrapper(int_vec &nums, int low, int high, int key);
//binary search function
int bin_search(int_vec &nums, int low, int high, int key);

int main(void)
{
	int_vec nums;			//vector to store integers.
	int n, r, key, index;
	cout<<"Number of ints and range: \n";
	cin>>n>>r;
	cout<<"Key :\n";
	cin>>key;
	cout<<"Number of ints : "<<n<<" and range : "<<r<<" and Key : "<<key<<"\n";
	nums.resize(n);
	generate_vector(nums, r);
	//print_vector(nums);
	index = bin_search_wrapper(nums,0,n-1,key);
	if(index!=-1)
		cout<<"Key : "<<key<<" found at, sorted vector, index : "<<index<<"\n"; 
	else
		cout<<"Key does not exist.\n";
	return 0;
}//end main

int bin_search_wrapper(int_vec &nums, int low, int high, int key)
{
	sort(nums.begin(), nums.end());	//bin_search needs sorted array
	print_vector(nums);
	return bin_search(nums, low, high, key);
}//end binary_Search_wrapper

int bin_search(int_vec &nums, int low, int high, int key)
{
	if(low<=high)
	{
		int mid = low+ (high-low)/2;	//to avoid overflow for large values
		if(key==nums[mid])
			return mid;
		else if (key < nums[mid])
			return bin_search(nums, low, mid-1, key);
		else
			return bin_search(nums, mid+1, high, key);
	}
	return -1;
}//end binary_search