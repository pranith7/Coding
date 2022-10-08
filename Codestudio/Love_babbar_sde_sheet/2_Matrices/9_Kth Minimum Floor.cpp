#include<bits/stdc++.h>
using namespace std;

/*
   Time Complexity : O(N * log(N) * log(Maximum Element in the Square City)
   Space Complexity: O(1)

   Where N is the number of Rows or Columns in Square City.
*/

int lesserThanEqualToMid(vector<int> &arr, int target, int n) {
    int mid, low = 0, high = n;

    // Till low is less than high
    while (low < high) {
        // Find the middle index
        mid = low + (high - low) / 2;

        if (target >= arr[mid]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int kMinFloor(vector<vector<int>> &squareCity, int n, int k) {

    int low = squareCity[0][0], high = squareCity[n - 1][n - 1], mid = 0, answer = low;

    while (low < high) {
        mid = low + (high - low) / 2;
        int num = 0;

        for (int i = 0; i < n; i++) {
            int pos = lesserThanEqualToMid(squareCity[i], mid, n);
            num += pos;
        }

        if (num < k) {
            low = mid + 1;
            answer = low;
        } else {
            high = mid;
        }
    }

    return answer;
}


int kMinFloor(vector<vector<int>> &squareCity, int n, int k) {
	// Write your code here.
    vector<int> v;
    for(int i = 0;i<squareCity.size();i++)
        for(int j = 0;j<squareCity[i].size();j++)
            v.push_back(squareCity[i][j]);
    sort(v.begin(),v.end());
    return v[k-1];
}


int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> squarecity(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>squarecity[i][j];
    }
    int ans;
    ans = kMinFloor(squarecity,n,k);
    cout<<ans<<endl;
    return 0;
}