#include<bits/stdc++.h>
using namespace std;


void solve(int i,int n)
{
    if(i<1) return; //Base case
    solve(i-1,n);   //Recursive approach
    cout<<i<<endl;  // calculation work
}

int main()
{   

    int t;
    cin>>t;
    while(t--)
    {
        int num;
        cin>>num;
        solve(num,num);
    }
    
    return 0;
}