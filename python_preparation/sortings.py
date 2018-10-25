# Algorithm	Time Complexity

# 			Best	    Worst
# Quicksort	Ω(nlog(n))	O(n^2)
# Mergesort	Ω(nlog(n))	O(nlog(n))


# Bubble sort

# for every element - move to the end

def bubble_sort(arr):
	for i in range(len(arr)):
		for j in range(len(arr) - i - 1):
			if arr[i] < arr[i+1]:
				arr[i], arr[i+1] = arr[i+1], arr[i]
	return arr

# Merge sort

# Divide in two parts recursively and then merge already sorted

def merge(left_arr, right_arr):
	merged_arr = []
	left_p = 0
	right_p = 0

	while left_p < len(left_arr) and right_p < len(right_arr):
		if left_arr[left_p] > right_arr[right_p]:
			merged_arr.append(right_arr[right_p])
			right_p += 1
		elif left_arr[left_p] <= right_arr[right_p]:
			merged_arr.append(left_arr[left_p])
			left_p += 1
	while left_p < len(left_arr):
		merged_arr.append(left_arr[left_p])
		left_p += 1
	while right_p < len(right_arr):
		merged_arr.append(right_arr[right_p])
		right_p += 1

	return merged_arr

def merge_sort(arr):
	if len(arr) < 2:
		return arr

	mid = len(arr) // 2
	left_sorted = merge_sort(arr[:mid])
	right_sorted = merge_sort(arr[mid:])
	return merge(left_sorted, right_sorted)

# Quick sort

# Find the partition index (pivot) and quick sort two parts around it

def partition(arr):
	mid = len(arr) // 2
	pivot = arr[mid]

	left = 0
	right = len(arr) - 1
	while left < right:
		while arr[left] < pivot:
			left += 1
		while arr[right] > pivot:
			right -= 1
		if left < right:
			arr[left], arr[right] = arr[right], arr[left]
			left += 1
			right -= 1
	return left

def quick_sort(arr):
	print (arr)
	if len(arr) < 2:
		return arr
	index = partition(arr)
	quick_sort(arr[:index-1])
	quick_sort(arr[index:])

# def test_decorator(func):
# 	def wrapper(*args, **kwargs):
# 		sorted_arr = func(*args, **kwargs)
# 		return sorted_arr
# 	return wrapper

# @test_decorator

def sorting_test(arr, sorted_arr):
	my_sorted_arr = quick_sort(arr)
	# print (sorted_arr, arr)
	return "OK" if sorted_arr == my_sorted_arr else "Test failed"

# print(sorting_test([1,3,2], [1,2,3]))
# print(sorting_test([1], [1]))
# print(sorting_test([], []))
print(sorting_test([5,4,3,2,1], [1,2,3,4,5]))
# print(sorting_test([1,2,3,4,5], [1,2,3,4,5]))