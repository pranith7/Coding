#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s,int x)
{   
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int t = s.top();
    s.pop();
    solve(s,t);
    s.push(t);
}

void reverse(stack<int> &s)
{
    //Base case
    if(s.empty())
        return;
    //calculation
    int t = s.top();
    s.pop();
    //Recursive approach
    reverse(s);
    solve(s,t);
}
int main()
{   
    int n,x;
    stack<int> s;
    cin>>n;
    for(int i=0;i<n;i++)
        s.push(i);
    // solve(s,x);
    // cout<<"Before Reversal"<<endl;
    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    reverse(s);
    // cout<<endl;
    cout<<"After reversal"<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}