#include<bits/stdc++.h>
using namespace std;


int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    if(n == 0) return 0;
    int left = INT_MAX;
    left = frogJump(n - 1, heights) + abs(heights[n] - heights[n - 1]);
    if(n>1) 
    {
        int right = INT_MAX;
        right = frogJump(n - 2, heights) + abs(heights[n] - heights[n - 2]); // right

    }
    if(left < right) return left;
    return right;
       
}


int main()
{   
    int n;
    cin>>n;
    vector<int> heights;
    for(int i=0;i<n;i++)
    {
        cin>>heights[i];
    }
    cout<<frogJump(n, heights);

    return 0;
}