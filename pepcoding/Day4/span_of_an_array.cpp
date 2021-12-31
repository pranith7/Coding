#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n,max,min;
    cin>>n;
    max = INT_MIN;
    min = INT_MAX;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>max)
        {
            max = a[i];
        }
        if(a[i]<min)
        {
            min = a[i];
        }
    }
    cout<<max-min;
    return 0;
}