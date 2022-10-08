#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{   
    int current_sum = INT_MIN;
    int largest_sum = 0;
    for(int i=0;i<n;i++)
    {
        current_sum += arr[i];
        largest_sum = max(largest_sum,current_sum);
        if(current_sum < 0) current_sum = 0;
    }
    return largest_sum;

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
    solve(arr,n);
    cout<<"output of the array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
