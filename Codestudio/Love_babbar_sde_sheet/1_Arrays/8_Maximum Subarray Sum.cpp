#include <bits/stdc++.h>
using namespace std;



long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    if(n == 0) return 0;
    long long int sum = 0;
    long long int global_sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        global_sum = max(global_sum,sum);
        if(sum < 0) sum = 0;
    }
    
    return global_sum;
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
    int ans = maxSubarraySum(arr,n);
    cout<<"output: "<<ans<<endl;
}