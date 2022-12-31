#include <bits/stdc++.h>
using namespace std;

int mod =(int)1e9+7;

/*
        The targetSum function is a dynamic programming solution for finding the number of ways to split the given array 
        into two subsets such that the difference between the sums of the subsets is equal to the given target value.

        The function starts by calculating the total sum of the array elements. If the difference between the total sum and the 
        target value is negative or not divisible by 2, the function returns 0 as it is not possible to split the array into two 
        subsets with the given difference.

        Otherwise, the function calls the findWays function, which is a variation of the classic 0/1 knapsack problem. The findWays 
        function takes the array and the target difference value as inputs and returns the number of ways to pick a subset of the array
        such that the sum of the subset is equal to the target difference.

        The findWays function uses a bottom-up dynamic programming approach to solve the problem. It starts by initializing a prev 
        array with the base cases. If the first element of the array is 0, both the prev[0] and prev[0] elements are set to 2, as there
        are two possible cases - either pick or not pick the element. If the first element is not 0, only the prev[0] element is set to 1,
        as there is only one case - not pick the element. If the first element is not 0 and less than or equal to the target difference, 
        the prev[num[0]] element is set to 1, as there is only one case - pick the element.

        The function then iterates over the rest of the elements of the array and for each element, it calculates the number of ways 
        to pick or not pick the element such that the sum of the subset is equal to the target difference. The number of ways is calculated
        using the values from the previous iteration stored in the prev array. The calculated values are stored in a cur array, which is 
        then used as the prev array for the next iteration.

        Finally, the function returns the prev[tar] element, which holds the number of ways to pick a subset of the array such that the sum 
        of the subset is equal to the target difference.


*/
int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(tar+1,0);
        for(int target= 0; target<=tar; target++){
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken)%mod;
        }
        prev = cur;
    }
    return prev[tar];
}

int targetSum(int n, int target, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-target <0 || (totSum-target)%2 ) return 0;
    
    return findWays(arr,(totSum-target)/2);
}
  

int main() {

  vector<int> arr = {1,2,3,1};
  int n = arr.size();
  int target=3;
                                 
  cout<<"The number of subsets found is " <<targetSum(n,target,arr);
}