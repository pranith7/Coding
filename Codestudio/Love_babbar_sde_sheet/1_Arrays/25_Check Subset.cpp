#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N + M)
    Space Complexity: O(N)

    Where N and M are the lengths of the ARR1 and ARR2 respectively.
*/

#include<unordered_map>

bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    // If arr2 is larger, it can't be subset.
    if (m > n) {
        return false;
    }
    // Map to store the frequency of each elements of array arr1.
    unordered_map<int, int> map;
    // Store the element of arr1 with its frequency in map.
    for (int i = 0; i < n; i++) {
        map[arr1[i]]++;
    }
    for (int i = 0; i < m; i++) {
        // If arr2[i] is not in map then return false.
        if (map.find(arr2[i]) == map.end()) {
            return false;
        }
        // Else decrease its frequency by 1.
        else {
            map[arr2[i]]--;
            // If at any point, frequency becomes negative then return false.
            if (map[arr2[i]] < 0) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    cout<<checkSubset(arr1,arr2,n,m)<<endl;
    return 0;
}