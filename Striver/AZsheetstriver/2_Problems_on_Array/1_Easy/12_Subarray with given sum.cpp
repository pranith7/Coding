#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums,int k)
{       

/*
        The subarraySum function takes a vector of integers called nums and an integer k as input, and 
        returns the number of contiguous subarrays in nums whose elements sum to k.

        The function first initializes a variable currsum to 0 and a variable res to 0. The currsum variable
        will be used to store the sum of the elements in the current subarray being processed, and the res 
        variable will be used to count the number of subarrays that sum to k.

        The function then iterates through the elements of the vector from index 0 to n-1, where n is the 
        size of the vector. For each element nums[i], the function adds it to the currsum and checks if 
        currsum is equal to k. If currsum is equal to k, this indicates that the current subarray sums to k, 
        and the res variable is incremented.

        The function also uses an unordered_map called prevsum to keep track of the number of times each 
        possible sum has been seen so far in the input array. The function checks if prevsum contains an entry 
        for currsum - k. If it does, this indicates that there is at least one subarray whose elements sum to k 
        that ends at the current index i. The function increments res by the number of such subarrays.

        Finally, the function increments the count for currsum in the prevsum map, so that it can be used to 
        count subarrays ending at future indices.

        After all the elements have been processed, the function returns the total number of subarrays that sum to k.


*/
      int n = nums.size();
        unordered_map<int,int> prevsum;
        
        int currsum = 0;
        int res = 0;
        for(int i=0;i<n;i++)
        {
            currsum += nums[i];
            
            if(currsum == k)
                res++;
            
            if(prevsum.find(currsum - k) != prevsum.end())
                res += (prevsum[currsum - k]);
            
            prevsum[currsum]++;
        }
        
        return res;

}


int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);

    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<subarraySum(nums,k);
    return 0;
}