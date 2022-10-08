private:
    void solve(int idx,vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans)
    {
        ans.push_back(temp);
        for(int i=idx;i<nums.size();i++)
        {
            if(i!=idx and nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,nums,temp,ans);
        return ans;    
    }