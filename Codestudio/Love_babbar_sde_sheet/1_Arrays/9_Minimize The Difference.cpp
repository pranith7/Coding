#include<bits/stdc++.h>
using namespace std;

int minimizeIt(vector<int> arr, int k)
{    
    sort(arr.begin(),arr.end());
	int n = arr.size();
    int min_,max_,ans = arr[n-1] - arr[0];
    for(int i=1;i<n;i++)
    {
        max_ = max(arr[i-1]+k,arr[n-1]-k);
        min_ = min(arr[i]-k,arr[0]+k);
        if(min_ < 0) continue;
        ans = min(ans,(max_-min_));
    }
    return ans;
}


int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans = minimizeIt(arr,k);
    cout<<"output"<<ans<<endl;
    return 0;
}