#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> a,int k)
{
    int start = 0;
    int end = a.size() - 1;
    while(start<=end)
    {
        int mid = (start + end)/2;
        if(a[mid] == k)
        {
            return mid;
        }
        else if(a[mid]<k)
        {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
    // cout<<"NOT Found"<<endl;
}

int main()
{   
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int  x =binarysearch(a,k);
    if(x!=-1) cout<<"Found";
    else cout<<"NOT";
    return 0;
}