#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int flag = 0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==k)
        {   
            flag = 1;
            cout<<i;
        }
        
    }
    if(flag==0) cout<<-1;
    return 0;
}