#include <bits/stdc++.h>
using namespace std;

/*
    The function canPartition checks whether a given array of integers can be partitioned 
    into two sets such that the sum of elements in both sets is equal.

    The function first checks if the sum of all the elements in the array is odd or not. 
    If it is odd, 
        then it is not possible to partition the array into two sets with equal sum, so the function 
        returns false.

    If the sum is even, 
        the function proceeds to create a table prev of size k+1, where k is half of the s
        um of all elements in the array. prev is initialized with true at index 0 and false at all other indices.

    The function then sets prev[arr[0]] to true if arr[0] is less than or equal to k.

    The function then iterates over the elements of the array from index 1 to n-1. 
    For each iteration, it creates a new table cur of size k+1 and initializes it with
    true at index 0 and false at all other indices. It then iterates over the indices
    of cur from 1 to k and sets cur[target] to true if either prev[target] or prev[target - arr[ind]] is true. 
    This is because cur[target] will be true if either the element at index target in the previous table is 
    true or if the element at index target - arr[ind] in the previous table is true and arr[ind] can be 
    added to it to get the target sum.

    Finally, the function returns the value at index k in the last table, which represents whether it is 
    possible to partition the array into two sets with equal sum
*/
bool canPartition(int n, vector<int> &arr){
    
    int totSum=0;
    
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    if (totSum%2) return false;
    
    else{
        int k = totSum/2;
        vector<bool> prev(k+1,false);
    
        prev[0] = true;
        
        if(arr[0]<=k)
            prev[arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            vector<bool> cur(k+1,false);
            cur[0] = true;
            for(int target= 1; target<=k; target++){
                bool notTaken = prev[target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = prev[target-arr[ind]];
            
                cur[target]= notTaken||taken;
            }
            prev = cur;
        }
        
        return prev[k];
    } 
}

int main() {

  vector<int> arr = {2,3,3,3,4,5};
  int n = arr.size();
                                 
  if(canPartition(n,arr))
    cout<<"The Array can be partitioned into two equal subsets";
  else 
    cout<<"The Array cannot be partitioned into two equal subsets";
}