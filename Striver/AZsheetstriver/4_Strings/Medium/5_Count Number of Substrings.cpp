#include<bits/stdc++.h>
using namespace std;

/*
	The function solve() takes in a string s and an integer k and returns the number of substrings of s 
	which have exactly k unique characters.

The function first initializes an array freq of size 26, which keeps track of the frequency of each 
character in the substring. It then uses two pointers, l and r, which mark the start and end of the 
substring, respectively. The variable cnt keeps track of the number of unique characters in the substring.

The function then enters a while loop that runs while l is less than the length of s. It decrements the 
frequency of the character at index l in freq, and increments the count cnt if the frequency is 0. This 
means that the character at index l is a unique character in the substring.

The function then enters a second while loop which runs while cnt is greater than k and r is less than or 
equal to l. In this loop, the function increments the frequency of the character at index r in freq, and 
decrements cnt if the frequency is 0. This means that the character at index r is no longer a unique character 
in the substring.

After both while loops have finished executing, the function increments the count ans by the number of elements
in the substring (which is l - r + 1) and increments l by 1. The function then repeats this process until l becomes
equal to the length of s.

The function substrCount() calls solve() twice, once with k and once with k - 1, and returns the difference 
between the two results. This gives the number of substrings of s which have exactly k unique characters.	
*/
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