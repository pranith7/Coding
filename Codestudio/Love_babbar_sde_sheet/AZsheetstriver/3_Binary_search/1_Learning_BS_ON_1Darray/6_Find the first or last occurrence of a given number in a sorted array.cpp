//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int nums[], int n , int target)
{
    // code here
     vector<int> ans(2, -1);
        int start = 0, end = n - 1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] < target) start = mid+1;
            else {
                if(nums[mid] == target) ans[0] = mid;
                end = mid-1;
            }
        }
        start = 0, end = n-1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] > target) end = mid-1;
            else {
                if(nums[mid] == target) ans[1] = mid;
                start = mid+1;
            }
        }
        return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends