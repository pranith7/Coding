//{ Driver Code Starts
/*
        
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of
bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all 
of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool isPossible(vector<int> &piles, int N, int m, int H){
        int hoursTake = 0;
        for (int i = 0 ; i < N ; i++){
            hoursTake += ceil(piles[i]/double(m));
        }
        return hoursTake <= H;
    }
  public:
    int minDays(int N, vector<int>& piles, int H) {
        // Code here
        int l = 1;
        int h = 0;
        for (int x : piles){
            h = max(h, x);
        }
        int res = 0;
        while (l <= h){
            int m = (l+h) >> 1;
            
            if (isPossible(piles, N, m, H)){
                res = m;
                h = m-1;
            }else{
                l = m+1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.minDays(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends