//{ Driver Code Starts
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
    int Solve(int N, vector<int>& piles, int H) {
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

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends