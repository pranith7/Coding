// Lower Bound
// Given an array of integers A (sorted) and a integer Val.

// Implement a function that takes A and Val as input parameters and returns the lower bound of Val.

// Note : If Val is not present in array then Lower bound of a given integer means integer which is just smaller than given integer.

// Otherwise Val itself is the answer.

// If Val is less than smallest element of array A then return '-1' in that case.



// Example 1  :

// A = [-1, -1, 2, 3, 5]

// Val = 4

// Answer :  3

// Since 3 is just smaller than 4 in the array.

// Example 2  :

// A = [1, 2, 3, 4, 6]

// Val = 4

// Answer :  4
// Since 4 is equal to 4.

#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n,int val)
{       
      int pos = 0;
      sort(arr,arr + n);
      for(int i=0;i<n;i++)
      {
          if(arr[i] > val) 
            pos = i - 1;
            break;
      }
      return arr[pos];  
}

int main()
{   
    int n,val;
    cin>>n>>val;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    solve(arr,n,val);
    cout<<"output of the array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
