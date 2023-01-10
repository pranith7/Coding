#include<bits/stdc+.h>
using namespace std;

int maximumsubarraysum(vector<int>&arr,int k)
{
    int n = arr.size();
    int j;
    int i=0,sum=0,ans;
    while(j<k)
    {   
       
       if(j-i+1<k)
       {
             j++;
       }
       else if (j-i+1==k)
       {
          ans = max(ans,sum);
          sum = sum - arr[i];
           j++;
           i++;
       }
    }

    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<maximumsubarraysum(arr)<<" "<<endl;
    return 0;
}

