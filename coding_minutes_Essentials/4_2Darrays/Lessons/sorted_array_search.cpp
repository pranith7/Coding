#include<bits/stdc++.h>
using namespace std;

pair<int,int> solve(vector<vector<int>> &arr,int target)
{
        int n = arr.size();
        int m = arr[0].size();

        if(target<arr[0][0] or target>arr[n-1][m-1])
        {
            return {-1,-1};
        }
        int i=0,j=m-1;
        while(i<=n-1 and j>=0)
        {   
            if(arr[i][j] == target)
            {
                return{i,j};
            }
            else if(arr[i][j]>target)
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
        int n,m,target;
        cin>>n>>m>>target;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
        pair<int,int> coordinates = solve(arr,target);
        // display(arr);
        cout<<coordinates.first<<" "<<coordinates.second;
    }
    
    return 0;
}