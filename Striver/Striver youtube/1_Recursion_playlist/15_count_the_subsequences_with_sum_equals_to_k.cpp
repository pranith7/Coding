#include<bits/stdc++.h>
using namespace std;

/*----------------------------------------------------------------

Subsequence of a string or array is a contingous or non contigous sequence 
which follows the order of the array or string 
*/
int subsequence(int i,vector<int> &temp,int n,int arr[],int s,int sum)
{
    if(i == n) 
    {   
        if(s == sum)
        {
           return 1;
        }
        return 0;
    }
    
    temp.push_back(arr[i]);
    s = s + arr[i]; 
    int l = subsequence(i+1,temp,n,arr,s,sum);
    temp.pop_back();
    s -= arr[i];
    int r = subsequence(i+1,temp,n,arr,s,sum);
    return l + r;
}

int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int> temp;
    cout<<"The subsequences are as follows"<<endl;
    int s = 0;
    cout<<subsequence(0,temp,n,arr,s,sum);
    return 0;
}