from utilities import print_list, generate_list

#Function to get occuarances of key
def get_occurances(nums, low, high, key):
	i =low	
	j=high
	comparisions=0
	#First occurance,moving "i" towards first occurance
	while i<j:
		comparisions +=1
		mid = i + (j-i)/2
		if key <=nums[mid]:	j = mid
		else: i = mid+1
	#check if key is found
	if not nums[i]==key:	return 0
	#start contains first occurance index
	start =i
	#Finding second occurance,setting "j" only not "i",array(i to j) contain elements greater or equal to key
	j= high
	while i<j:
		comparisions +=1
		mid = i + (j-i)/2+1;
		if key <nums[mid]:	j = mid-1
		else:	i=mid
	end =j
	print "Number of comparisions for n : ",n," is 2*logn(base2) : ",comparisions
	return end-start+1

if __name__ == '__main__':
	print "Enter Number of ints, range and key (between 0 to range)  rexpectively:"
	n = int(raw_input())
	r = int(raw_input())
	key = int(raw_input())
	print "Number of ints",n," range",r," and key ", key
	nums = generate_list(n,r)
	nums.sort()
	print_list(nums)
	occuarances = get_occurances(nums,0, n-1, key)
	print "occuarances of key : ",key," is : ",occuarances


