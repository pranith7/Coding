#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
    //Brute Approach
    int subarraysum = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int currentsum = 0;
            for(int k = i;k<=j;k++)
            {
                currentsum += arr[k];
            }
            subarraysum = max(subarraysum,currentsum);
        }
    }
    // return subarraysum;

    //Using Prefix sum
    int prefix[n+1];// 1 2 3 4 5 // 1 3 6 10 15
    prefix[0] = arr[0];
    int subarraysum1 = 0;
    for(int i=1;i<n;i++)
    {
        prefix[i] = prefix[i-1] + arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int currentsum1 = 0;
            currentsum1 = prefix[j] - prefix[i-1];
            subarraysum1 = max(currentsum1,subarraysum1);
        }
    }
    
    // return subarraysum1;

    //Using Kadanes Algorithm
    int subarraysum2 = 0;
    int currentsum2 = 0;
    for(int i=0;i<n;i++)
    {
        currentsum2 += arr[i];
        subarraysum2 = max(subarraysum2,currentsum2);
        if(currentsum2 <= 0) currentsum2 = 0;
       
    }
    return subarraysum2;

}

int main()
{   
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<solve(arr,n);
    cout<<endl;
    cout<<"output of the array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}