#include<bits/stdc++.h>
using namespace std;

// aux[rbi][rbj] - aux[tli-1][rbj] - 
//    aux[rbi][tlj-1] + aux[tli-1][tlj-1]
int solve(vector<vector<int>> &arr,int sr,int sc,int er,int ec)
{
        int n = arr.size();
        int m = arr[0].size();


}

int main()
{   

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,sr,sc,er,ec;
        cin>>n>>m>>sr,sc,er,ec;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
        cout<<solve(arr,sr,sc,er,ec);
    }
    
    return 0;
}