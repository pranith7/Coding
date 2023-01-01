#include <bits/stdc++.h>
using namespace std;

/*
    This code defines a class Solution with a member function findPath. The findPath function receives
    a 2D integer array m and an integer n as input and returns a vector of strings. It has a helper 
    function solve which is a recursive function that traverses the 2D array and generates a path as a
    string of moves (UP, DOWN, LEFT, RIGHT) that can be taken to reach the bottom right corner of the 
    array from the top left corner. The solve function takes in the current position (i, j), the input
    array a, the size n, a reference to the vector of strings ans, a string move representing the path 
    of moves taken so far, and a 2D vector of integers vis representing the visited positions. The base
    case for the recursion is when the current position (i, j) is the bottom right corner of the array.
    In this case, the path of moves is added to the ans vector. The solve function then considers four 
    possible moves - down, left, right and up - in this order and invokes itself recursively for each 
    of these moves if the new position is valid (inside the array boundaries and not already visited). 
    
    The findPath function initializes the vis array and invokes the solve function with the top left 
    corner as the starting position.
*/
class Solution{
    public:
    void solve(int i,int j,vector<vector<int>> &a,int n,vector<string> &ans,string move,vector<vector<int>> &vis)
    {
        if(i==n-1 and j==n-1)
        {
            ans.push_back(move);
            return;
        }
        //downward
        if(i+1<n and !vis[i+1][j] and a[i+1][j]==1)
        {
            vis[i+1][j]=1;
            solve(i+1,j,a,n,ans,move+"D",vis);
            vis[i+1][j]=0;
        }
        //left
        if(j-1>=0 and !vis[i][j-1] and a[i][j-1]==1)
        {
            vis[i][j]=1;
            solve(i,j-1,a,n,ans,move+"L",vis);
            vis[i][j]=0;

        }
        //right
        if(j+1<n and !vis[i][j+1] and a[i][j+1]==1)
        {
            vis[i][j+1]=1;
            solve(i,j+1,a,n,ans,move+"R",vis);
            vis[i][j+1]=0;
        }
        //Upward
        if(i-1>=0 and !vis[i-1][j] and a[i-1][j]==1)
        {
            vis[i][j]=1;
            solve(i-1,j,a,n,ans,move+"U",vis);
            vis[i][j]=0;
        }

    }



    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int> (n,0));
        if(m[0][0] == 1) solve(0,0,m,n,ans,"",vis);
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends