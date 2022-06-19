#include<bits/stdc++.h>
using namespace std;

void solve(int &n,int &m,int i,int j)
{
    int a = (~0)<<(j+1);
    int b = (1<<i) - 1;
    int mask = a|b;
    n = n&mask;
    m = m<<i;
    n = n|m;

}



int main()
{
    int n,m,i,j;
    cin>>n>>m>>i>>j;
    solve(n,m,i,j);
    cout<<n<<endl;
    return 0;
}