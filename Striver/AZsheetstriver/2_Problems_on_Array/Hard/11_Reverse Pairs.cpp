#include<bits/stdc++.h>
using namespace std;

/*
    The given code is an implementation of a Merge Sort based solution to the problem of counting the 
    number of pairs (i, j) such that i < j and arr[i] > 2 * arr[j]. The function reversePairs takes a 
    vector of integers arr as input and returns the number of such pairs.

    The function first calls MergeSort on the input array, which is a recursive function that divides 
    the array into two halves, sorts them using the Merge function, and then merges them back together. 
    The Merge function takes three arguments: the array being sorted, the starting index of the current 
    subarray (low), the ending index of the current subarray (high), and the middle index (mid) of the 
    subarray, which is calculated as the floor of the average of low and high.

    The Merge function first counts the number of pairs (i, j) such that i is in the left half of the 
    subarray being considered and j is in the right half, and arr[i] > 2 * arr[j]. It does this by 
    iterating through the left half of the subarray and using a pointer to iterate through the right half,
    incrementing the pointer whenever arr[i] > 2 * arr[j]. The total number of such pairs is added to a 
    variable total.

    Next, the Merge function sorts the subarray using a modified version of the merge sort algorithm. 
    It creates two pointers, one pointing to the start of the left half of the subarray and the other 
    pointing to the start of the right half. It then compares the elements at these pointers and adds 
    the smaller of the two to a temporary vector t. It continues this process until one of the pointers 
    reaches the end of its respective half. It then adds the remaining elements from the other half to 
    the temporary vector. Finally, it copies the elements from the temporary vector back into the original
    array and returns the value of total.
*/

int Merge(vector < int > & nums, int low, int mid, int high) {
  int total = 0;
  int j = mid + 1;
  for (int i = low; i <= mid; i++) {
    while (j <= high && nums[i] > 2LL * nums[j]) {
      j++;
    }
    total += (j - (mid + 1));
  }

  vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}
int MergeSort(vector < int > & nums, int low, int high) {

  if (low >= high) return 0;
  int mid = (low + high) / 2;
  int inv = MergeSort(nums, low, mid);
  inv += MergeSort(nums, mid + 1, high);
  inv += Merge(nums, low, mid, high);
  return inv;
}
int reversePairs(vector < int > & arr) {
  return MergeSort(arr, 0, arr.size() - 1);
}

int main() {
  vector<int> arr{1,3,2,3,1};
  cout << "The Total Reverse Pairs are " << reversePairs(arr);
}   