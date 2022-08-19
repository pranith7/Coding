#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
    int n = arr.size();
    int j = n-1;
    for(int i = 0;i<n;i++)
    {
        if(i>m and i<j)
        {
            swap(arr[i],arr[j]);
            j--;
        }
    }
    
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    reverseArray(arr,m);
    cout<<"Output of the array "<<endl;
    for(auto i:arr) 
    {   
        cout<<i<<" ";
    }
    return 0;
}




