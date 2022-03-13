#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> arr)
{
        
}

void display(vector<int> arr)
{
        cout<<"output of the array is"<<endl;
        for(int i=0;i<arr.size()-1;i++)
        {
            cout<<arr[i]<<" ";
        }
}

int main()
{   

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<arr.size()-1;i++)
        {
            cin>>arr[i];
        }
        solve(arr);
        display(arr);
    }
    
    return 0;
}