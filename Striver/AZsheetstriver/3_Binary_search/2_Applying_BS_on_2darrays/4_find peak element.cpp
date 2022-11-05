#include<bits/stdc++.h>
using namespace std;

int findpeakelements(vector<int> &arr,int low,int high,int n)
{
    int mid = low + (high - low)/2;
    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid])){
        return arr[mid];
    }

    else if(mid > 0 and arr[mid-1] > arr[mid]){
        findpeakelements(arr,low,mid-1,n);
    }

    else{
        findpeakelements(arr,mid+1,high,n);
    }



}

int main()
{   
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout<<findpeakelements(arr,0,n-1,n);

    return 0;   
}