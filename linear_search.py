
from utilities import generate_list, print_list

#Linear Search function
def lin_search(nums, key):
	for number in nums:
		if number == key:	return nums.index(number)
	return -1

if __name__ == '__main__':
	print "Enter Number of ints, range and key (betwenn 0 to ranege)  rexpectively:"
	n = int(raw_input())
	r = int(raw_input())
	key = int(raw_input())
	nums = generate_list(n,r)
	print_list(nums)
	index = lin_search(nums, key)
	if not index ==-1:	print "Key : ",key, " found at index : ",index
	else:				print "Key not found"
