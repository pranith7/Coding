//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int search(int nums[],int n,int target)
    {
    //   int n = nums.size()-1;
        int left = 0;
        int right = n-1;
        while(left <= right)
        {   
            int mid = left + (right-left/2);
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target)
                right = mid -1;
            else
                left = mid+1;
            
        }
        return 0;
    }
    int searchInSorted(int arr[], int N, int K) 
    { 
    
       // Your code here
       bool p = search(arr,N,K);
       if(p) return 1;
       else return -1;
       
    }
};

//{ Driver Code Starts.


int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 

// } Driver Code Ends