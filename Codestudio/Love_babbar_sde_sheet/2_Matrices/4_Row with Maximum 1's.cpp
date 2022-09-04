#include<bits/stdc++.h>
using namespace std;



int rowMaxOnes(vector<vector<int>>& mat, int n, int m) {
    // Write your code here.
    int row = 0,col = m-1,ans = 0;
    while(row  < n and col >= 0)
    {
        if(mat[row][col] == 1)
        {
            ans = row;
            col--;
        }
        else
        {
            row++;
        }
        
    }
    return ans;
}

int main()
{   
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int> (m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>mat[i][j];
        }
    }
    int ans = rowMaxOnes(mat, n, m);
    cout<<ans<<endl;
    return 0;
}

