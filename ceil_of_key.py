'''
Problem statement : given an array of N integers, find ceil value of key;
Say A = [0,1,2,3,4,5,6], key 5
ceil value is 6
key may be present in the array
'''
from utilities import print_list, generate_list

#Funtion returns ceil value of key
def get_ceil(nums, low, high, key):
	if key >nums[high]:	return -1

	while low<high:
		'''THIS BELOW LINE IS IMP FOR FLOOR AND CEIL FUNCTION'''
		mid = low + (high-low)/2;
		#we want value bigger than key
		#So skip values smaller or equal to key
		if nums[mid]<= key:	low = mid+1
		#and keep index on value which is bigger than key
		else:	high = mid
	return nums[low]		#or nums[high]. Both same

if __name__ == '__main__':
	print "Enter Number of ints, range and key (between 0 to range)  rexpectively:"
	n = int(raw_input())
	r = int(raw_input())
	key = int(raw_input())
	print "Number of ints",n," range",r," and key ", key
	nums = generate_list(n,r)
	nums.sort()
	print_list(nums)
	ceil = get_ceil(nums,0, n-1, key)
	if not ceil ==-1:	print "ceil of key : ",key, " is : ",ceil
	else:				print "ceil not found"	

