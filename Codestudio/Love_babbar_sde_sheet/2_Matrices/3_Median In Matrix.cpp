#include<bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if(n*m == 0)
        return 0;
    else if(n*m == 1)
    	return matrix[0][0];

    vector<int> ans;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) ans.push_back(matrix[i][j]);
    } 
    sort(ans.begin(), ans.end());
    int index = (n*m + 1) / 2;
    int median = ans[(n*m)/2]; // ans[index -1]
    return median;

}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int> (m));
    int ans = findMedian(matrix);
    cout<<ans<<endl;
    return 0;
}


/*

Binary search approach
The rows of the input matrix are sorted, so we can use this property of the matrix to solve the problem. Binary search works on sorted arrays and thus binary search can be used to find median in this case. The idea is that for a number to be median there should be exactly (N/2) elements that are less than it. So, find that number using binary search.

 

Algorithm:

The first column will contain all the minimum values of all the rows and the last column will contain all the maximum values of all the rows. Find the minimum and maximum values of the input matrix using the first and the last column respectively.
Use binary search on the range of numbers ranging from minimum and maximum values found in step 1. Find their middle value and find the count of numbers in the matrix which are less than the middle value, and accordingly change the values of maximum and minimum.
For a number to be median, there should be (N*M)/2 numbers smaller than that number. So for every number, we get the count of numbers less than that in each row of the matrix. If the count is less than the required count, the median must be greater than the current selected value, else it must be lesser.
Return the value of median.
Time Complexity
O(N*(log(M))), where N & M are the number of rows and columns of the input matrix respectively.

 

The function for finding the count of the values less than any key in a row using binary search algorithm takes log(M) time. This is done for all the rows resulting into O(N*(log(M))) time. So the final time complexity will be O(N*(log(M))).

Space Complexity
O(1)

 

Constant extra space is required.










    /*

	Time complexity: O(N*(log(M)))
	Space complexity: O(1)
	
	where N & M are the number of rows and columns of the matrix respectively.



#include <algorithm>

int findMedian(vector<vector<int> > &arr, int n, int m){
	
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



*/