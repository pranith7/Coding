#include<bits/stdc++.h>
using namespace std;


vector<int> twosum(vector<int> &nums,int target)
{
    vector<int> res;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i) {

   	 if (mp.find(target - nums[i]) != mp.end()) {

   		 res.emplace_back(i);
   		 res.emplace_back(mp[target - nums[i]]);
   		 return res;
   	 }

   	 mp[nums[i]] = i;
    }

    return res;
}


int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];
    
    vector<int> ans;
    ans = twosum(arr,target);

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}