//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        /*
            The leaders function is a member function of the Solution class that takes an array of integers 
            called a and an integer n as input, and returns a vector of integers containing the leaders in 
            the array a.

            A leader in an array is an element that is greater than all the elements to its right.

            The function first declares a vector of integers called v and an auxiliary array of integers called t, 
            which will be used to store the maximum element to the right of each element in the array a.

            It then initializes the variable max1 with the value of the last element in the array a, and 
            enters a loop that iterates over the elements of a in reverse order, starting from the second 
            to the last element. For each element a[i], it updates max1 with the maximum of max1 and a[i], 
            and stores the value of max1 in the corresponding element of the array t.

            The function then enters another loop that iterates over the elements of a from the first to the 
            second to the last element. If the element a[i] is equal to the corresponding element of the array t, 
            it pushes the value of a[i] onto the v vector.

            Finally, the function pushes the value of the last element in the array a onto the v vector and returns it.
        */
        vector <int> v;
        int t[n-1];
        int max1 = a[n-1];
        for (int i=n-2; i>=0; i--){
            max1 = max(max1,a[i]);
            t[i] = max1;
        }
        for (int i=0; i<n-1; i++){
            if(a[i]==t[i]){
                v.push_back(a[i]);
            }
        }
        v.push_back(a[n-1]);
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends