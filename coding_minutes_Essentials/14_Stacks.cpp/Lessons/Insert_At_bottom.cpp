#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s,int x)
{   
    vector<int> arr;
    while(!s.empty())
    {
        arr.push_back(s.top());
        s.pop();
    }
    s.push(x);
    for(int x : arr)
        s.push(x);
}

int main()
{   
    int n,x;
    stack<int> s;
    cin>>n>>x;
    for(int i=0;i<n;i++)
        s.push(i);
    solve(s,x);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}