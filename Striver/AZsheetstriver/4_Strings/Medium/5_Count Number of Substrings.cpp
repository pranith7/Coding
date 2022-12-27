//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

//User function template for C++

class Solution
{
  public:
    long long int solve(string &s, int k){
        int n=s.size();
    	vector<int> freq(26,0);
    	int l=0,r=0;
    	long cnt=0;
    	long ans=0;
    	while(l<n){
    	    if(freq[s[l]-'a']==0){
    	        cnt++;
    	    }
    	    freq[s[l]-'a']--;
    	    while(cnt>k && r<=l){
    	        freq[s[r]-'a']++;
    	        if(freq[s[r]-'a']==0){
    	            cnt--;
    	        }
    	        r++;
    	    }
    	    ans+=l-r+1;
    	    l++;
    	}
    	return ans;
    }
    long long int substrCount (string s, int k) {
        return solve(s,k)-solve(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends