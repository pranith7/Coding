//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int arr[], int N){
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