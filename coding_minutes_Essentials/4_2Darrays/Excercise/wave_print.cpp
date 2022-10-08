#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int>> arr)
{       
        vector<int> ans;
        int n = arr.size();
        int m = arr[0].size();
        int startrow = 0;
        int endrow = n-1;
        int startcol = 0;
        int endcol = m-1;
        while(startcol<=endcol)
        { 
            for(int row = startrow;row<=endrow;row++)
            {
                ans.push_back(arr[row][endcol]);
            }
            endcol--;
            for(int row = endrow;row >= startrow; row--)
            {
                ans.push_back(arr[row][endcol]);
            }
            endcol--;
        }

        return ans;

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
        vector<int> ans = solve(arr);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        // display(arr);
    }
    
    return 0;
}