#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    if((n&(n-1)) == 0) 
        cout<<"n is a power of two"<<endl;
    else 
        cout<<"ITS not"<<endl;
    // cout<<n<<endl;
    return 0;
}