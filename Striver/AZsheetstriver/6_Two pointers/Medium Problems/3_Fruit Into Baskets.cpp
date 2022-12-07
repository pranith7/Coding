//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> m;
        int i = 0,j = 0,ans = 0;
        while(j<n)
        {   
            m[fruits[j]]++;
            if(m.size()<3) 
            {
                ans = max(ans,j-i+1);
                j++;
            } 
            else
            {
                while(m.size()>2)
                {
                    m[fruits[i]]--;
                    if(m[fruits[i]]==0) m.erase(fruits[i]);
                    i++;
                }
                j++;
            }

        }
        return ans;
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruit(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends