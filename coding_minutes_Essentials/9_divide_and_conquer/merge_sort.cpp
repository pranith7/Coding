#include<bits/stdc++.h>
using namespace std;


//helper function
void merge(vector<int> &arr,int s,int e)
{
    int i = s;
    int m = (s+e)/2;
    int j = m+1;
    vector<int> temp;
    while(i<=m and j<=e)
    {
        if(arr[i]<arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);    
    }
    //copy remaining elements from first array
    while(i<=m) 
    {
        temp.push_back(arr[i++]);
    }
    //copy remaining elements from second array
    while(j<=e)
    {
        temp.push_back(arr[j++]);
    }
    //copying elements from temp array to original array
    int k =0;
    for(int i=s;i<=e;i++)
    {
        arr[i] = temp[k++];
    }
     return;

}

//sorting Method
void mergesort(vector<int> &arr,int s,int e)
{
    if(s>=e) return;
    int mid = (s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    return merge(arr,s,e);

}

int main()
{   
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<=n-1;i++)
        {
            cin>>arr[i];
        }
        int s = 0,e = n-1;
        mergesort(arr,s,e);
        for(int x : arr)
        {
            cout<<x<<",";
        }
    return 0;
}