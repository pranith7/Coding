#include<bits/stdc++.h>
using namespace std;


int partitiion(vector<int> &arr,int s,int e)
{
    int pivot = arr[e];
    int i = s-1;
    for(int j=s;j<e;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[i+1],pivot);
    return i+1;
}

void quicksort(vector<int> &arr,int s,int e)
{   
    if(s>=e)
    {
        return;
    }
    int p = partitiion(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);

}
int main()
{   
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<=arr.size()-1;i++)
        {
            cin>>arr[i];
        }
        quicksort(arr,0,n-1);
        for(int x:arr)
        {
            cout<<x<<",";
        }
    
    return 0;
}