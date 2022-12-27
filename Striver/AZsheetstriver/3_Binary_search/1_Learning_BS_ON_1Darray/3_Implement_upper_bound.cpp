//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    pair<int,int> p;
    // p.push_back({-1,-1});
    int floor=-1;
        int ceil=INT_MAX;
        int var = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)
            {
                floor=arr[i];
                ceil=arr[i];
            }
            else if(arr[i]<x)
            {
                floor=max(floor,arr[i]);
            }
            else
            {
                ceil= min(ceil,arr[i]);
            }
        }
        
        if(ceil == var) {  ceil=-1; }
        // p.push_back({floor,ceil});
        return {floor,ceil};
    
}