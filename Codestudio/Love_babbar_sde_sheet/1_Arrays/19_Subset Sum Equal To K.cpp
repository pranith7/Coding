#include<bits/stdc++.h>
using namespace std;

/*

    Time Complexity : O(2^N)
    Space Complexity : O(N)

    Where N is the number of elements in the array.

    
*/

int helper(vector < int > & arr, int n, int k) {
    // Base condition.
    if (n <= 0) {
        // If k = 0, we reached target sum.
        if (k == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    // arr[n-1] not taken in considertion.   
    int x = helper(arr, n - 1, k);
    int y = 0;
    if(k - arr[n-1] >= 0){
        // arr[n-1] taken in considertion.
        y = helper(arr, n - 1, k - arr[n-1]);    
    }

    // Return current result.
    return x || y;
}

bool subsetSumToK(int n, int k, vector < int > & arr) {
    // Calling recursive function.
    int ans = helper(arr, n, k);
    if (ans == 1) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector < int > arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (subsetSumToK(n, k, arr)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}