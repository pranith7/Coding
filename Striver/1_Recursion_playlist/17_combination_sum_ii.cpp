class Solution {
private:
    void findcombinations(int idx,vector<int> &candidates,int target,vector<vector<int>> &ans,vector<int> &temp)
    {
            if(target == 0)
            {
                ans.push_back(temp);
                return;
            }
        
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx and candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            findcombinations(i+1,candidates,target-candidates[i],ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()); //O(nlog(n))
        vector<vector<int>> ans;
        vector<int> temp;
        findcombinations(0,candidates,target,ans,temp);
        return ans;
        
    }
};