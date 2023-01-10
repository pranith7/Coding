#include<bits/stdc+.h>
using namespace std;

vector<int> maximumsubarraysum(vector<int>&arr,int k)
{   
    vector<int> result; 
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
           if(arr[i]<0) result.psuh_back(arr[i]);
           else result.push_back(0);    
           j++;
           i++;
       }
    }

    return result;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<maximumsubarraysum(arr)<<" "<<endl;
    return 0;
}

