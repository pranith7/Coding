#include<bits/stdc++.h>
using namespace std;


int minSubArrayLen(vector<int>& nums, int target, int n) {
   if(nums.size() == 0) return 0;
        int result = INT_MAX;
        int current_sum = 0;
        int startingindex = 0;
        for(int i=0;i<nums.size();i++)
        {
            current_sum += nums[i];
            while(current_sum >= target)
            {
                result = min(result,i+1-startingindex);
                current_sum -= nums[startingindex];
                startingindex++;
            }
        }
        
        return (result != INT_MAX) ? result : 0;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,target;
        cin>>n>>target;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        int result = minSubArrayLen(nums,target,n);
        cout<<result<<endl;
        
    }
    return 0;
}