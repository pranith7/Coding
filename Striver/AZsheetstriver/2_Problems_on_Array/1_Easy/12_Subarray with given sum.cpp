#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums,int k)
{
      int n = nums.size();
        unordered_map<int,int> prevsum;
        
        int currsum = 0;
        int res = 0;
        for(int i=0;i<n;i++)
        {
            currsum += nums[i];
            
            if(currsum == k)
                res++;
            
            if(prevsum.find(currsum - k) != prevsum.end())
                res += (prevsum[currsum - k]);
            
            prevsum[currsum]++;
        }
        
        return res;

}


int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);

    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<subarraySum(nums,k);
    return 0;
}