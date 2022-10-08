#include<bits/stdc++.h>
using namespace std;

void solve(int i,int sum)
{
    if(i<1) 
    {   
        cout<<sum;
        return;
    }
    solve(i-1,sum+i);
}

int main()
{
    int n;
    cin>>n;
    int sum=0;
    solve(n,0);
    return 0;
}
