#include<bits/stdc++.h>
using namespace std;

int solve(int &n)
{
    int count = 0;
    while(n>0)
    {
        int last_bit = (n&1);
        count += last_bit;
        n = n>>1;
    }
    return count;
}
int solve_hack(int n)
{
    int count = 0;
    while(n>0)
    {   
        n = n&(n-1);
        count++;
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    cout<<solve_hack(n)<<endl;
    
    return 0;
}