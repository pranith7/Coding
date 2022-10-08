#include<bits/stdc++.h>
using namespace std;

bool compare(int a,int b)
{
    // return a>b; --> for reverse
    return a<b;  // --> for sort
}

int main()
{   
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    // sort(a.begin(),a.end(),compare);
    sort(a.begin(),a.end(), greater<int>());
    for(int x : a)
    {
        cout<<x<<" ";
    }
}