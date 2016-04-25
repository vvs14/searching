'''
@author : Vivek Vikram Singh
@date : 10.03.16

Given an array of integers. Find a peak element in it.
An array element is peak if it is NOT smaller than its neighbors. 
For corner elements, we need to consider only one neighbor. 
For example, for input array {5, 10, 20, 15}, 20 is the only peak element. 
For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. 
Note that we need to return any one peak element.
'''
from utilities import print_list, generate_list

#function to find and return peak element
def get_peak(nums, low, high):
	while low < high-1:
		mid = low + (high-low)/2
		if nums[mid]<= nums[mid+1]:	low = mid
		else:	high = mid
	if nums[low] > nums[high]:	return nums[low]
	else: 	return nums[high]

if __name__ == '__main__':
	print "Enter Number of ints, range rexpectively:"
	n = int(raw_input())
	r = int(raw_input())
	print "Number of ints",n," range",r
	nums = generate_list(n,r)
	#UNCOMMENT BELOW LINE TO SEE OUTPUT ON SORTED ARRAY
	#nums.sort()
	print_list(nums)
	peak = get_peak(nums,0, n-1)
	print "Peak element is : ",peak
