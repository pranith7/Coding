#include<bits/stdc++.h>
using namespace std;

vector<int> kRotate(vector<int> a, int k)
{
    // your code  goes here
    int val;
    while(k--)
    {   
        val = a[a.size()-1];
        for(int i = a.size()-1;i>=0;i--)
        {
            a[i] = a[i-1];
        }
        
        a[0] = val;
        val = a[a.size()-1];
    }
    return a;
}