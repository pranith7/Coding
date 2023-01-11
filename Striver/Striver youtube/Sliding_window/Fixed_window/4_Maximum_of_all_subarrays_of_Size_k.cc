#include <deque>
#include <iostream>
#include <vector>


/*
    This function takes two arguments as input: a vector arr representing the input array and an integer k representing the size of the subarrays.
It uses a deque (double-ended queue) to keep track of the maximum element of the current window. The deque stores the indices of the elements, rather than their values.
It iterates through the array, and for each element:

Removes elements from the front of the deque that are out of the current window.
Removes elements from the back of the deque that are smaller than the current element.
Pushes the current element's index onto the deque.
Prints the front element of deque as maximum element of the current window if i >= k-1
The time complexity of this function is O(n) and the space complexity is O(k). Because at any point deque will contain atmost k elements

This will give the maximum of all sub arrays of size k in the given array, in the same order as they appear in the input array.
Please keep in mind that this is one of the several ways to accomplish this task, depending on the specific requirements of your use case, different solution could also be available.
*/
void max_of_subarrays(const std::vector<int>& arr, int k) {
    std::deque<int> q;

    // Traverse through all array elements
    for (int i = 0; i < arr.size(); i++) {
        // Remove elements that are out of the current window
        while (!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }

        // Remove elements that are smaller than the current element
        while (!q.empty() && arr[q.back()] < arr[i]) {
            q.pop_back();
        }

        // Add the current element to the deque
        q.push_back(i);

        // Print the maximum element of the current window
        if (i >= k - 1) {
            std::cout << arr[q.front()] << " ";
        }
    }
}

int main() {
    std::vector<int> arr = {12, 1, 78, 90, 57, 89, 56};
    int k = 3;
    max_of_subarrays(arr, k);
    return 0;
}


