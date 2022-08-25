#include<bits/stdc++.h>
using namespace std;

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 
{
    // Write your code here.
    vector<int> result;
    int startrow = 0;
    int startcol = 0;
    int endrow = n-1;
    int endcol = m-1;
    
    while(startrow <= endrow and startcol <= endcol)
    {
        for(int col = startcol;col<=endcol;col++)
        {
            result.push_back(matrix[startrow][col]);
        }
        for(int row = startrow+1;row <=endrow;row++)
        {
            result.push_back(matrix[row][endcol]);
        }
        for(int col = endcol-1;col>=startcol;col--)
        {    
            if(startrow == endrow) break;
            result.push_back(matrix[endrow][col]);
        }
        for(int row = endrow -1;row>=startrow+1;row--)
        {    
            if(startcol == endcol) break;
            result.push_back(matrix[row][startcol]);
        }
        startrow++;
        startcol++;
        endrow--;
        endcol--;   
    }
    return result;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<int> result;
    result = spiralPathMatrix(matrix,n,m);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";

    }
    return 0;
}