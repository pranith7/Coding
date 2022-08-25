#include<bits/stdc++.h>
using namespace std;

pair<int, int> search(vector<vector<int>> matrix, int x)
{
    // Write your code here.
    int row = 0, column = matrix.size()-1;
    while((row>=0 && row<matrix.size())&&((column>=0 && column<matrix.size())))
    {
        if(matrix[row][column]==x)
            return {row,column};
        else if(matrix[row][column]<x)
            row++;
        else
            column--;
    }
    return {-1,-1};
}

int main()
{
    int t;
    cin>>t;
    while(t--)
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
        int x;
        cin>>x;
        pair<int, int> result = search(matrix,x);
        cout<<result.first<<" "<<result.second<<endl;

    }

    return 0;
}