#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &arr)
{
        int n = arr.size();
        int m = arr[0].size();

        int startrow = 0;
        int endrow = n-1;
        int startcol = 0;
        int endcol = m-1;

        while(startcol<=endcol and startrow<=endrow)
        {   
            for(int col=startcol;col<=endcol;col++)
            {
                cout<<arr[startrow][col]<<" ";
            }
            for(int row=startrow+1;row<=endrow;row++)
            {
                cout<<arr[row][endcol]<<" ";
            }
            for(int col=endcol-1;col>=startcol;col--)
            {   
                if(startrow == endrow)
                {
                    break;
                }
                cout<<arr[endrow][col]<<" ";
            }
            for(int row=endrow-1;row>=startrow+1;row--)
            {   
                if(startcol == endcol) 
                {
                    break;
                }
                cout<<arr[row][startcol]<<" ";
            }
            startrow++;
            startcol++;
            endcol--;
            endrow--;
        }



}

void display(vector<vector<int>> &arr)
{        
        int n = arr.size();
        int m = arr[0].size();
        cout<<"output of the matrix array is"<<endl;
         for(int i=0;i<n;i++)
        {   
            for(int j=0;j<m;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        
}

int main()
{   

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
        solve(arr);
        // display(arr);
    }
    
    return 0;
}