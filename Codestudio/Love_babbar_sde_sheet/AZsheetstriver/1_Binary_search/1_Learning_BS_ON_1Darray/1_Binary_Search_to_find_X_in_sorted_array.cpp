#include<bits/stdc++.h>
using namespace std;


int search(vector<int>& nums,int target)
{
      int n = nums.size()-1;
        int left = 0;
        int right = n;
        while(left <= right)
        {   
            int mid = left + (right-left/2);
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target)
                right = mid -1;
            else
                left = mid+1;
            
        }
    return -1;
}


int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<search(arr,target)<<endl;
    // cout<<ans<<endl;
    return 0;
}

    // let mid = lo + Math.floor((hi-lo+1)/2);
    //     if (target < nums[mid]) {
    //         hi = mid - 1
    //     } else {
    //         lo = mid; 
    //     }
    // }
    // return nums[lo]==target?lo:-1;
