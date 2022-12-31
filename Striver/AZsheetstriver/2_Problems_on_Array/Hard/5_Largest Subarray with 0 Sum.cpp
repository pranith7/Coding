//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // LArgest subaary with sum 0
        /*
            The maxLen function is a solution to the problem of finding the length of the 
            largest subarray with a sum of 0 in a given array A of size n.

            The function first declares an unordered map mpp that maps the sum of elements 
            in the subarray to their indices. It also declares two variables, maxi and sum, 
            which are initialized to 0.

            The function then iterates through the elements of the array, adding each element
             to sum. If sum is equal to 0, maxi is updated to the current index plus 1 
             (since the subarray starts at index 0). If sum is not equal to 0, the function 
             checks if sum is present in the map. If it is, maxi is updated to the difference 
             between the current index and the index stored in the map for sum. If sum is not 
             present in the map, it is added to the map with the current index.

            Finally, the function returns maxi, which is the length of the largest subarray with a sum of 0.
        */
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends