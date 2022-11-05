//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int nums[], int beg, int end, int target){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        
        int  mid;
        while(beg<=end)
        {   

            while(beg < end and nums[beg] == nums[beg+1]) 
                beg++;
            
            while(beg < end and nums[end] == nums[end-1])
                end--;

            mid=(beg+end)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[beg]<=nums[mid])
            {
                if(target<=nums[mid] && target>=nums[beg])
                    end=mid-1;
                else
                    beg=mid+1;
            }
            
            else
            {
                if(target>=nums[mid] && target<=nums[end])
                   beg=mid+1;
                else
                    end=mid-1;
            }
            
        }
        
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends