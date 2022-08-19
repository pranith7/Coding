   
   
    void solve(int idx,int total,vector<int> &arr,vector<int> &sumsubset)
    {
        if(idx == arr.size())
        {
            sumsubset.push_back(total);
            return ;
            
        }
        //pick the element
        solve(idx+1,total+arr[idx],arr,sumsubset);
        //Not pick the element
        solve(idx+1,total,arr,sumsubset); 
    }