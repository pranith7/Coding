#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &matrix)
{
        int rows = matrix.size();
        int cols = matrix[0].size();
        int k = 0;
        vector<int> a;
        for(int i=rows-1;i>=0;i--)
            for(int j=0;j<cols;j++)
                a.push_back(matrix[i][j]);
                
        for(int i=0;i<cols;i++)
            for(int j=0;j<rows;j++)
                matrix[j][i] = a[k++];
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