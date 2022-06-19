#include<bits/stdc++.h>
using namespace std;

void getithbit(int n,int i)
{
    int mask = 1<<i;
    if(n&mask)
        cout<<1<<endl;
    else
        cout<<0<<endl;
}

void setithbit(int &n,int i)
{
    int mask = 1<<i;
    n = n|mask;
    cout<<n;
}
void clearithbit(int &n,int i)
{
    int mask = 1<<i;
    mask = (~mask);
    n = n&mask;  

}

void updateithbit(int &n,int i,int val)
{   
    clearithbit(n,i);
    int mask = (val<<i);
    n = n|mask;
}

void clearlastithbits(int &n,int i)
{
    int mask = (-1<<i);
    n = n&mask;
}

void clearbitsinrange(int &n,int i,int j)
{
    int a = (~0)<<(j+1);
    int b = (1<<i) - 1;
    int mask = a|b;
    n = n&mask;
}

int main()
{   

    int a=0;
    // cout<<(~a);// NOT operator

    int b = 11;
    // cout<<(b>>1);// right shift  b/2^1
    // cout<<(b<<1);// left shift   b*2^1

    /*  
    To check if a number is odd or even
    if(b&1)
        cout<<"ODD";
    else
        cout<<"EVEN";


    Get ith bit
    */
   int n,pos,endpos;
   cin>>n>>pos>>endpos;

   clearbitsinrange(n,pos,endpos);
   cout<<n<<endl;

    return 0;
}