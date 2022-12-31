// Binary Search based C++ program to find number
// of rotations in a sorted and rotated array.
#include <bits/stdc++.h>
using namespace std;

// Returns count of rotations for an array which
// is first sorted in ascending order, then rotated
/*
	This function is a solution to the problem of finding the number of times an array 
	has been rotated. The array is assumed to be sorted and rotated by some number of 
	positions to the right.

	The function takes 3 parameters as input:

	arr: an array of integers representing the sorted and rotated array
	low: an integer representing the lower bound of the current subarray being searched
	high: an integer representing the upper bound of the current subarray being searched
	The function returns an integer representing the number of times the array has been rotated.

	The function uses a recursive binary search algorithm to find the number of rotations. 
	The base cases for the recursion are when the subarray being searched has only one element 
	(high is equal to low) or when the subarray is empty (high is less than low). In these cases, 
	the function returns low or 0 respectively.

	The function then calculates the middle index of the current subarray and checks if the element
	at this index or the element at the next index is the minimum element in the array. If either 
	of these elements is the minimum, the function returns the index of the minimum element.

	If neither of these elements is the minimum, the function decides whether to search the 
	left or right half of the current subarray by comparing the element at the end of the 
	subarray (arr[high]) with the element at the middle index (arr[mid]). If arr[high] is 
	greater than arr[mid], the function searches the left half of the current subarray by calling
	 itself with the updated bounds low and mid - 1. If arr[high] is less than or equal to arr[mid], 
	 the function searches the right half of the current subarray by calling itself with the updated 
	 bounds mid + 1 and high.


*/
int countRotations(int arr[], int low, int high)
{
	// This condition is needed to handle the case
	// when the array is not rotated at all
	if (high < low)
		return 0;

	// If there is only one element left
	if (high == low)
		return low;

	// Find mid
	int mid = low + (high - low) / 2; /*(low + high)/2;*/

	// Check if element (mid+1) is minimum element.
	// Consider the cases like {3, 4, 5, 1, 2}
	if (mid < high && arr[mid + 1] < arr[mid])
		return (mid + 1);

	// Check if mid itself is minimum element
	if (mid > low && arr[mid] < arr[mid - 1])
		return mid;

	// Decide whether we need to go to left half or
	// right half
	if (arr[high] > arr[mid])
		return countRotations(arr, low, mid - 1);

	return countRotations(arr, mid + 1, high);
}

// Driver code
int main()
{
	int arr[] = { 15, 18, 2, 3, 6, 12 };
	int N = sizeof(arr) / sizeof(arr[0]);
	cout << countRotations(arr, 0, N - 1);
	return 0;
}
