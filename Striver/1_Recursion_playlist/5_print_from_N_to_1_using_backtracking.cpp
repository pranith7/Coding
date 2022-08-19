#include<bits/stdc++.h>
using namespace std;

void solve(int i,int n)
{
    if(i>n) return;         //Base case
    solve(i+1,n);           //Recursive approach
    cout<<i<<endl;          // calculation work
}

int main()
{
    int n;
    cin>>n;
    solve(1,n);

    return 0;
}