'''
@author : Vivek Vikram Singh
@date : 10-03-2016

Problem Statement: Given a sorted array of distinct elements, and the array is rotated at an unknown position. 
Find minimum element in the array.
No input as elements must be distinct and "rand()" may generate duplicates.
Algorithm tested on Arrays in program only.
'''

from utilities import print_list

#function to find minimum
def get_min(nums, low, high):
	while low<high:
		mid = low + (high-low)/2;
		'''Compare mid element with high always rather than low
		 as in two elements case, mid will equal to low only
		 and you will compare mid element with low only
		 and you miss high element in comparision'''
		if nums[mid] < nums[high]:	high =mid
		else: low = mid +1
	return nums[low]

if __name__ == '__main__':
	#nums = [14,15,1,3,4,5,6,7,8,9,10,11,12,13]
	#nums = [3,4,5,6,7,8,9,10,11,12,13,14,1,2]
	#nums = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
	nums = [20,21,22,23,1,2,3,4,5,6,7,8,9]
	size = len(nums)
	print_list(nums)
	print "minimum of array is : ", get_min(nums, 0, size-1)
