//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	double multiply(int n, int mid){ //avoiding integer overflow
	    
	    double mul = 1;
	    for(int i=1; i<=n; i++)
	        mul = mul * mid;
	        
	    return mul;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
        
	    
	    int beg = 1, end = m;
	    
	    while(beg <= end){
	        
	        int mid = (beg + end) >> 1;
	        
	        if(multiply(n, mid) == m)
	            return mid;
	            
	        else if(multiply(n, mid) < m)
	            beg = mid + 1;
	            
	        else
	            end = mid - 1;
	    }
	    
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends