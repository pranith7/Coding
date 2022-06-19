#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b)
{
    int ans = 1;
    while(a>0)
    {
        int last_bit = (b&1);
        if(last_bit)
        {
            ans = ans*a;
        }
        a = a*a;
        b=b>>1;
    }
    return ans;
}


int main()
{
    int a,b;
    cin>>a>>b;
    cout<<solve(a,b);
    return 0;
}