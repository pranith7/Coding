#include<iostream>
using namespace std;

void subArrWithSumKOptimal(int arr[], int n, int k) {
  /*
      The subArrWithSumKOptimal function takes an array of integers arr, the size of the array n, 
      and an integer k as input, and finds all subarrays of arr that have a sum of k.

      The function uses two pointers, start and end, to keep track of the current subarray being 
      considered. It initializes start to 0 and end to -1, and sum to 0.

      The function then enters a loop that runs as long as start is less than n. Inside the loop, 
      it enters another loop that increments end as long as end + 1 is less than n and the sum of 
      the elements from start to end + 1 is less than or equal to k. It updates sum with the sum of
      the elements from start to end + 1 at each iteration.

      If sum becomes equal to k at any point, the function prints the current subarray and a newline.

      After the inner loop ends, the function subtracts the element at start from sum and increments
      start by 1.

      After the outer loop ends, the function terminates.
  */
  int start = 0, end = -1, sum = 0;
  while (start < n) {
    while ((end + 1 < n) && (sum + arr[end + 1] <= k))
      sum += arr[++end];

    if (sum == k) {
      for (int p = start; p <= end; p++)
        cout << arr[p] << " ";
      cout << "\n";
    }
    sum -= arr[start];
    start++;
  }

}
int main() {

  int arr[] = {1, 9, 3, 7};
  int n = sizeof(arr) / sizeof(arr[0]), k = 10;
  cout << "Subarray with given sum is: " << endl;
  subArrWithSumKOptimal(arr, n, k);

  return 0;
}