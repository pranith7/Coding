//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // int i = 0, j = 0, sum = 0;
        // int maxLen = 0;
       
        // while (j < N) {
        //     sum += A[j];
        //     if (sum < K) 
        //     {
        //         j++;
        //     }
        //     else if (sum == K) 
        //     {
        //         maxLen = max(maxLen, j-i+1);
        //         j++;
        //     }
        //     else if (sum > K) {
                
        //         while (sum > K) 
        //         {
        //             sum -= A[i];
        //              i++;
        //         }
        //         if(sum == K)  maxLen = max(maxLen, j-i+1);
        //         j++;
        //     }
        // }
        // return maxLen;
    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;
 
    // traverse the given array
    for (int i = 0; i < n; i++) {
 
        // accumulate sum
        sum += arr[i];
 
        // when subarray starts from index '0'
        if (sum == k)
            maxLen = i + 1;
 
        // make an entry for 'sum' if it is
        // not present in 'um'
        if (um.find(sum) == um.end())
            um[sum] = i;
  
        // check if 'sum-k' is present in 'um'
        // or not
        if (um.find(sum - k) != um.end()) {
 
            // update maxLength
            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }
 
    // required maximum length
    return maxLen;
        
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends