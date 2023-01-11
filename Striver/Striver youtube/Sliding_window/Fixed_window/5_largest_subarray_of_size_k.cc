#include <iostream>
#include <vector>

/*
    This function takes two arguments as input: a vector arr representing the input array and an integer k representing the size of the subarray.
It uses a sliding window technique to keep track of the current sum and the maximum sum of a subarray of size k.
First, the function initializes the current sum with the first k elements of the array, and sets the max_sum and max_start index accordingly.
Then, it iterates through the rest of the array and for each element, it updates the current sum by adding the new element and subtracting the first element of the current subarray, it also checks if this current sum is greater than max_sum if yes then it updates max_sum and max_start.
Finally, it copies the largest subarray from the input array to the max_subarray vector and returns the max_subarray.
*/
std::vector<int> largest_subarray(const std::vector<int>& arr, int k) {
    std::vector<int> max_subarray;
    int current_sum = 0;
    // Initialize the current sum with the first k elements
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }
    int max_sum = current_sum;
    int max_start = 0;
    // Iterate through the rest of the array
    for (int i = k; i < arr.size(); i++) {
        current_sum += arr[i] - arr[i - k];
        // Update the max sum and max start index
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_start = i - k + 1;
        }
    }
    // Copy the largest subarray to the max_subarray vector
    for (int i = max_start; i < max_start + k; i++) {
        max_subarray.push_back(arr[i]);
    }
    return max_subarray;
}

int main() {
    std::vector<int> arr = {12, 1, 78, 90, 57, 89, 56};
    int k = 3;
    std::vector<int> max_subarray = largest_subarray(arr, k);
    std::cout << "The largest subarray of size " << k << " is: ";
    for (int i : max_subarray) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
