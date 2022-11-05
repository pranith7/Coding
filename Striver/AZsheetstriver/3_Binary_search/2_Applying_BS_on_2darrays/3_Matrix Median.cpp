//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &arr, int n, int m){
        // code here
    int min = 100000000, max = -100000000; 
	
    for (int i = 0; i < n; i++) 
    { 
        // Finding the minimum element 
        if (arr[i][0] < min) {
        	min = arr[i][0];
		}
  
        // Finding the maximum element 
        if (arr[i][m-1] > max) {
        	max = arr[i][m-1];
		}      
    } 
    int desired = (n * m + 1) / 2;
	
	// Binary search to find the median 
    while (min < max) 
    { 
        int mid = min + (max - min) / 2; 
        
        // Stores count of the integers less than  mid
        int count = 0; 

        // Find count of elements smaller than mid 
        for (int i = 0; i < n; i++) {
        	count += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();	
		}
        if (count < desired) {	 
        	 min = mid + 1;
		} 
        else{	
        	max = mid;
		}	
    }     
    return min; 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends