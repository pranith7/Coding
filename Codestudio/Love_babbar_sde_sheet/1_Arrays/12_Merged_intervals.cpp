#include <bits/stdc++.h> 
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergedintervals;
        if(intervals.size() == 0) return mergedintervals;
        sort(intervals.begin(), intervals.end());
        
        vector<int> temp = intervals[0];
        
        for(auto it : intervals){
            if(it[0] <= temp[1]){
                temp[1] = max(it[1],temp[1]);
            }
            else{
                mergedintervals.push_back(temp);
                temp = it;
            }
        }
        mergedintervals.push_back(temp);
        return mergedintervals;
}

int main()
{   

    int n;
    cin>>n;
    vector<vector<int>> intervals(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>intervals[i][j];
        }
    }
    vector<vector<int>> mergedintervals = mergeIntervals(intervals);
    for(auto it : mergedintervals){
        cout<<it[0]<<" "<<it[1]<<endl;
    }

    return 0;
}









