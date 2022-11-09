//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	      vector <int> result;
	    vector <int> positive;
	    vector <int> negative;
	    
	    for (int i = 0; i < n; i++)
	    {
	        if (arr[i] < 0)
	            negative.push_back(arr[i]);
	        else
	            positive.push_back(arr[i]);
	    }
	    
	    int negCount = negative.size();
	    int posCount = positive.size();
	    
	    int indexPos = 0;
	    int indexNeg = 0;
	    
	    while (indexPos < posCount || indexNeg < negCount)
	    {
	        if (indexPos < posCount)
	        {
	            result.push_back(positive[indexPos]);
	            indexPos++;
	        }
	        if (indexNeg < negCount)
	        {
	            result.push_back(negative[indexNeg]);
	            indexNeg++;
	        }
	    }
	    
	    for (int i = 0; i < n; i++)
	        arr[i] = result[i];
	
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends