#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n,k,x;
    cin>>n>>k;

    int t = n;
    int nod = 0;
    while(t>0)
    {
        t = t/10;
        nod++;
    }
    k = k % nod;
    if(k<0)
    {
        k += nod;
    }
    int divisor = 1;
    int multiplier = 1;

    for(int i=1;i<=nod;i++)
    {
        if(i>k)//--> change the sign to left rotate
        {
            divisor = divisor*10;
        }   
        else
        {
            multiplier = multiplier*10;
        }
    }
        int q = n/divisor;
        int r = n%divisor;
        int  rot  = r*multiplier + q;
        cout<<rot;
    return 0;
}