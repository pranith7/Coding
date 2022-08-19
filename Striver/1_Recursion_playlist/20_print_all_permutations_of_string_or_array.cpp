#include<bits/stdc++.h>
using namespace std;

void permute(int arr[], int n, int freq[],vector<int> &temp,vector<vector<int>> &result)
{
    if(temp.size() == n) 
    {
        result.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!freq[i])
        {
            temp.push_back(arr[i]);
            freq[i] = 1;
            permute(arr,n,freq,temp,result);
            freq[i] = 0;
            temp.pop_back();
        }
    }
    
}

vector<vector<int>> solve(int arr[],int n)
{
    vector<vector<int>> result;
    vector<int> temp;
    int freq[n] = {0};
    for(int i = 0; i < n; i++) freq[i] = 0;
    permute(arr,n,freq,temp,result);
    return result;
}

int main()
{   
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>> ans = solve(arr,n);
    cout<<"Permutations of the given array are as follows:"<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}