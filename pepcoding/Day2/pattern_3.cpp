#include<bits/stdc++.h>
using namespace std;



int main()
{   
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {   
        
        for(int j=n-i;j>=1;j--)
        {
            cout<<"\t";
        }
        for(int j=i;j>=1;j--)
        {
            cout<<"*\t";
        }
        cout<<endl;
    }

    return 0;
}