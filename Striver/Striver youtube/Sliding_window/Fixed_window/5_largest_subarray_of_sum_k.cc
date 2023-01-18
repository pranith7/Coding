#include <iostream>
#include <unordered_map>
using namespace std;

/*
    The program uses a hashmap (unordered_map in C++11) to store the sum of elements seen so far 
    and their indices. It checks if the current sum minus k is present in the map, which means 
    that the subarray from the index of that sum to the current index has a sum of k. If it is, 
    it updates the maximum length of the subarray with sum k. If the current sum is equal to k, 
    it also updates the maximum length.
*/

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;

    int max_len = 0;
    int curr_sum = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        curr_sum += a[i];
        if (curr_sum == k) {
            max_len = i+1;
        } else if (map.find(curr_sum-k) != map.end()) {
            max_len = max(max_len, i-map[curr_sum-k]);
        }
        if (map.find(curr_sum) == map.end()) {
            map[curr_sum] = i;
        }
    }
    cout << "Maximum length of subarray with sum " << k << " is " << max_len << endl;
    return 0;
}
