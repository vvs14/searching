'''
Problem statement : given an array of N integers, find floor value of key;
Say A = [0,1,2,3,4,5,6], key 5
Floor value is 4
key may be present in the array
'''
from utilities import print_list, generate_list

#Funtion returns floor value of key
def get_floor(nums, low, high, key):
	if key < nums[low]:	return -1

	while low<high:
		'''THIS BELOW LINE IS IMP FOR FLOOR AND CEIL FUNCTION'''
		mid = low + (high-low)/2+1;
		#we want value smaller than key
		#So skip values bigger or equal to key
		if nums[mid]>= key:	high = mid-1
		#and keep index on value which is bigger than key
		else:	low = mid
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
	floor = get_floor(nums,0, n-1, key)
	if not floor ==-1:	print "Floor of key : ",key, " is : ",floor
	else:				print "floor not found"	

