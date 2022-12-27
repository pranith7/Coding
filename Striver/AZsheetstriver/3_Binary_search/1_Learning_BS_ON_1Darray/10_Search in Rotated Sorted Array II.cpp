//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& nums, int target) {
        // Code here
        int  beg = 0,end = N-1,mid;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(nums[mid]==target)
                return true;
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
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends