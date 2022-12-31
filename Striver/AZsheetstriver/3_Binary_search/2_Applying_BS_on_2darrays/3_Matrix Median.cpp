//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    /*
        This is a class that defines a solution to the problem of finding the median of a matrix of integers.

        The class has a single public method called median that takes in 3 parameters:

        arr: a 2D vector of integers representing the matrix
        n: an integer representing the number of rows in the matrix
        m: an integer representing the number of columns in the matrix
        The method returns an integer representing the median of the matrix.

The method first initializes min and max to the minimum and maximum possible integer values respectively. It then iterates through the rows of the matrix and updates min and max to the minimum and maximum element in the matrix respectively.

The method then calculates the desired index for the median by taking the average of (n * m + 1) / 2 and initializes a variable desired to this value.

The method then enters a loop that continues until min is no longer less than max. In each iteration of the loop, the method calculates the middle index of the current range and finds the number of elements in the matrix that are less than or equal to this value. The method then compares the number of such elements to desired. If the number of elements is less than desired, the method updates min to the middle index plus one and continues to the next iteration. If the number of elements is greater than or equal to desired, the method updates max to the middle index and continues to the next iteration.

When the loop ends, min will be the median of the matrix and the method returns this value.
    */
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