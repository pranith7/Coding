#include<bits/stdc++.h>
using namespace std;

int minimumJumps(vector<int> &arr, int n)
{
    int steps_left=0;
    int reach=0;
    int jumps=0;
    while(reach<n-1)
    {
        int farthest=0;
        for(int i=steps_left;i<=reach;i++)
        {
            farthest=max(farthest,arr[i]+i);
        }
        jumps++;
        steps_left=reach+1;
        if(farthest==reach) return -1;
        reach=farthest;
       
    }
    return jumps;
  
}



int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans = minimumJumps(arr,n);
    cout<<"output "<<ans<<endl;
    return 0;
}