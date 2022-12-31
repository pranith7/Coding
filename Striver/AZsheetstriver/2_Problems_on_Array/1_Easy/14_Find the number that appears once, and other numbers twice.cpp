//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int arr[], int N){

    /*
        The search function takes an array of integers arr and an integer N as input, and returns the element 
        in the array that appears only once. The array is assumed to contain multiple copies of most of its 
        elements, with one element appearing only once.

        The function uses a binary search approach to find the element that appears only once. It starts by 
        initializing two variables i and j to 0 and N-1, respectively, and a variable mid to the midpoint between i and j.

        The function then enters a loop that continues as long as i is less than or equal to j. Inside the loop, 
        the function checks the value of arr[mid] and compares it to the values of arr[mid-1] and arr[mid+1]. 
        Depending on the values of these elements and the parity of mid, the function adjusts the values of 
        i and j to narrow down the search range.

        If the value of arr[mid] is different from the values of arr[mid-1] and arr[mid+1], the function returns 
        arr[mid] as the result, since this is the element that appears only once. If the value of arr[mid] is 
        the same as one of the surrounding elements, the function adjusts the values of i and j to exclude that
        element and continue the search.

        After the loop ends, the function returns the value of arr[mid], which is the element that appears only once.
    */
	 int i = 0;
     int j = N-1;
     int mid = i + (j-i)/2;

     while(i<=j){
         if(mid%2==0 && arr[mid] == arr[mid+1]){
             i = mid + 1;
         }

         else if(mid%2==1 && arr[mid] == arr[mid-1]){
             i = mid + 1;
         }
        
         else if(mid%2 ==1 && arr[mid] == arr[mid+1]){
             j = mid - 1;
         }

         else if(mid%2==0 && arr[mid] == arr[mid-1]){
             j = mid-1;
         }
         else if(arr[mid]!=arr[mid+1] || arr[mid]!=arr[mid-1]){
             return arr[mid];
         }
         mid = i + (j-i)/2;
     }
     return arr[mid];
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends