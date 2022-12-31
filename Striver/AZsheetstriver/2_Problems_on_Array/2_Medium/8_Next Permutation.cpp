//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> nums){
        // code here
        /*
            The nextPermutation function takes an integer N and a vector of integers called nums as input, 
            and returns the next permutation of the elements in nums in lexicographic order.

            The function first declares three variables: n, which is the size of the nums vector; k, 
            which is used to keep track of the position of the first element in the permutation that is 
            smaller than the element immediately after it; and l, which is used to keep track of the 
            position of the smallest element in the permutation that is larger than the element at position k.

            The function then enters a loop that iterates over the elements of nums in reverse order, starting
            from the second to the last element. It updates k with the position of the first element that is 
            smaller than the element immediately after it. If no such element is found, k remains at the default 
            value of -1.

            If k is -1, this means that the permutation is already in descending order and cannot be further 
            modified. The function reverses the order of the elements in nums and returns the modified vector.

            If k is not -1, the function enters another loop that iterates over the elements of nums in 
            reverse order, starting from the last element. It updates l with the position of the smallest element 
            that is larger than the element at position k.

            The function then swaps the elements at positions k and l, and reverses the order of the elements in 
            the subvector of nums starting at position k + 1 and ending at the last element.

Finally, the function returns the modified vector.
        */
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--)
            if (nums[k] < nums[k + 1]) break;
        
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
    	}
    	return nums;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends