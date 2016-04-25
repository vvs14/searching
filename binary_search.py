'''
Binary search implementation
Input : Number of elements n, range r (o to r-1) and key .
Output : Index of key
'''
from utilities import print_list, generate_list

#binary search wrapper
def bin_search_wrapper(nums, low, high, key):
	nums.sort();
	print_list(nums)
	return bin_search(nums, low, high, key)

#bin search function
def bin_search(nums, low, high, key):
	if low<= high:
		mid = low + (high - low)/2;	#to avoid overflow
		if key == nums[mid]:	return mid
		elif key < nums[mid]:	return bin_search(nums, low, mid-1, key)
		else:	return bin_search(nums, mid+1, high, key)
	return -1;

if __name__ == '__main__':
	print "Enter Number of ints, range and key (between 0 to range)  rexpectively:"
	n = int(raw_input())
	r = int(raw_input())
	key = int(raw_input())
	print "Number of ints",n," range",r," and key ", key
	nums = generate_list(n,r)
	#print_list(nums)
	index = bin_search_wrapper(nums,0, n-1, key)
	if not index ==-1:	print "Key : ",key, " found at index : ",index
	else:				print "Key not found"