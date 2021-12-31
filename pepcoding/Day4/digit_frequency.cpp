#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int n,k,x;
    cin>>n;
    cin>>k;

    int count = 0;

    while(n>0)
    {
       x  = n%10;
       n /=10;
       if(x == k) count++;
    }

    cout<<count;
    return 0;
}
