//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {   
       /*
            This is a class that defines a solution to a problem involving finding the kth smallest element
            in the merge of two sorted arrays.

            The class has a single public method called kthElement that takes in 5 parameters:

            arr1: an array of integers representing the first sorted array
            arr2: an array of integers representing the second sorted array
            n: an integer representing the size of the first array
            m: an integer representing the size of the second array
            k: an integer representing the index of the element to be found
            The method returns an integer representing the kth smallest element in the merged array.

            The method first initializes 3 variables: i and j to keep track of the current indices in
            arr1 and arr2 respectively, and kth to keep track of the current index in the merged array.

            The method then enters a loop that continues until i is no longer less than n and j is no 
            longer less than m. In each iteration of the loop, the method compares the elements at the 
            current indices in arr1 and arr2. If the element in arr1 is smaller, the method increments 
            kth and checks if it is equal to k. If it is, the method returns the element in arr1. If it 
            is not, the method increments i and continues to the next iteration of the loop. If the element
             in arr2 is smaller, the method follows a similar process but uses arr2 and j instead.

            After the loop ends, one of the arrays will have been fully traversed. If arr1 still has 
            elements, the method enters a loop that continues until i is no longer less than n and 
            checks if kth is equal to k for each remaining element in arr1. If arr2 still has 
            elements, the method enters a similar loop but uses arr2 and j instead. If none of 
            the loops find the kth element, the method returns -1.
       */
      int i=0, j=0 , kth =0;
      while(i<n && j<m){
          if(arr1[i] < arr2[j]){
              kth ++;
       //check whether it is equal to the given value or not
                if(kth == k){       
                    return arr1[i];
                }
                else{
                    i++;
                }
            }
          else{
                kth ++;
                if(kth == k){
                    return arr2[j];
                }
                else{
                    j++;
                }
            }   
      }
    // if arr1 elements are remaining
      while(i < n){
            kth ++;
            if(kth == k){
                return arr1[i];
            }
            else{
                i++;
            }
      }  
    // if arr2 elements are remaining 
      while(j < m){
          kth ++;
            if(kth == k){
                return arr2[j];
            }
            else{
                j++;
            }
      }
        return -1;  //if none case is valid;

    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends