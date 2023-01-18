#include <iostream>
using namespace std;

int maxSubArrayLen(int a[], int n, int k) {
    int max_len = 0;
    int curr_sum = 0;
    for (int i = 0, j = 0; i < n; i++) {
        curr_sum += a[i];
        while (curr_sum > k && j <= i) {
            curr_sum -= a[j];
            j++;
        }
        if (curr_sum == k) {
            max_len = max(max_len, i - j + 1);
        }
    }
    return max_len;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;

    cout << "Maximum length of subarray with sum " << k << " is " << maxSubArrayLen(a, n, k) << endl;
    return 0;
}

/*
This program uses two pointers, one moving from left to right, and another 
moving from left to right but only when the sum exceeds the given k, then 
it start decrementing the sum and incrementing the second pointer. When the 
sum is equal to k, it updates the maximum length of the subarray with sum k.

*/