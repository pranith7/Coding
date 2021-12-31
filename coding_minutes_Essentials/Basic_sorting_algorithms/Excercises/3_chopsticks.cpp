#include<bits/stdc++.h>
using namespace std;

int pairSticks(vector<int> length, int D)
{
    // your code goes here
    int pairs = 0;
    sort(length.begin(),length.end());
    for(int i=0;i<length.size()-1;i++)
    {
        if(length[i+1] - length[i] <= D)
        {
            pairs++;
            i++;
        }
    }

    return pairs;
}