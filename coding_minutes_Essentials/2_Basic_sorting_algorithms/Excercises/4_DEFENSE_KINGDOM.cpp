#include<bits/stdc++.h>
using namespace std;

int defkin(int W, int H, vector<pair<int, int>> position)
{
    // your code goes here
    vector<int> a;
    vector<int> b;
    a.push_back(0);
    b.push_back(0);
    for(int i=0;i<=position.size()-1;i++)
    {
        a.push_back(position[i].first);
        b.push_back(position[i].second);
    }
    a.push_back(W+1);
    b.push_back(H+1);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int mx=0;
    int my=0;
    for(int i=0;i<a.size()-1;i++)
    {
        mx = max(mx,a[i+1]-a[i] - 1);
        my = max(my,b[i+1]-b[i] - 1);
    }
    return mx*my;
}