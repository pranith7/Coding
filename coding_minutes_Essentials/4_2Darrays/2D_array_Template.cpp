#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &arr)
{
        int n = arr.size();
        int m = arr[0].size();

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
        display(arr);
    }
    
    return 0;
}