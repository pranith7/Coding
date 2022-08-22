#include<bits/stdc++.h>
using namespace std;

int findMinDiff(int n, int m, vector<int> chocolates) {
    // Write your code here.
    sort(chocolates.begin(),chocolates.end());
    int d = INT_MAX;
    for(int i=0;i+m-1<n;i++)
    {
        d = min(d,chocolates[i+m-1]-chocolates[i]);
        
    }    
    return d;
}



int main()
{
    int n;
    cin>>n;
    vector<int> chocolates(n);
    int m;
    cin>>m;
    cout<<findMinDiff(n,m,chocolates)<<endl;
    return 0;
}