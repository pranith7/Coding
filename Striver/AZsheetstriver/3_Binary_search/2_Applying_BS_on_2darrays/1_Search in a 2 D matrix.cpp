#include<bits/stdc++.h>
using namespace std;

pair<int,int> searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[n-1][m-1])
            return {-1,-1};
        int i = 0,j = m-1;
        while(i<=n-1 and j >= 0)
        {
            if(matrix[i][j] == target)
            {
                return {i,j};
            }
            else if(matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return {-1,-1};
}


int main()
{
    int n,m,target;
    cin>>n>>m>>target;
    vector<vector<int>> arr(n,vector<int> (m));
    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    pair<int,int> p = searchMatrix(arr,target);
    cout<<p.first<<" "<<p.second<<endl;
    
    return 0;
}