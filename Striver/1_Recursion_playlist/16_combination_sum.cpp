// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {

//     return 0;   
// }



class Solution {
private:
    void findcombination(int idx,vector<int> &candidates,int target,vector<vector<int>> &res,vector<int> &temp)
    {
        if(idx == candidates.size())
        {
            if(target == 0) 
            {
                res.push_back(temp);
            }
            return;
        }
        if(candidates[idx] <= target)
        {
            temp.push_back(candidates[idx]);
            findcombination(idx,candidates,target-candidates[idx],res,temp);
            temp.pop_back();
        }
        
        findcombination(idx+1,candidates,target,res,temp);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> res;
            vector<int> temp;
            findcombination(0,candidates,target,res,temp);
            return res;
    }
};