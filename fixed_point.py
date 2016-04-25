'''
Given an array of n distinct integers sorted in ascending order, 
write a function that returns a Fixed Point in the array, if there is any Fixed Point present in array, else returns -1. 
Fixed Point in an array is an index i such that arr[i] is equal to i.
 Note that integers in array can be negative.
'''
from utilities import print_list

#Function to find fixed point in list
def get_fixed_point(nums, low, high):
	while low<=high:
		mid = low+ (high-low)/2
		if nums[mid]==mid:	return mid
		elif nums[mid] < mid: low = mid+1
		else:	high = mid-1
	return -1

if __name__ == '__main__':
	#nums = [-10, -5, 0, 3, 7]
	nums = [0, 2, 5, 8, 17]
	#nums = [-10, -5, 3, 4, 7, 9]
	print_list(nums)
	fixed = get_fixed_point(nums,0, len(nums)-1)
	if not fixed==-1:	print "Fixed point is : ",fixed
	else:	print "No fixed point in list"