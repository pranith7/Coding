#include<bits/stdc++.h>
using namespace std;

bool check_(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<arr[i-1])
            return false;
    }

    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Answer is ::"<<endl;
    cout<<check_(arr)<<endl;
    return 0;
}