#include<bits/stdc++.h>
using namespace std;


/*  
    Approach 1
    Time Complexity = O(N ^ 2 * log(N))
    Space Complexity = O(N)

    Where N is the number of rows in the matrix.
*/

#include <queue>

class Triplet {
public:
    int val;
    int row;
    int col;

    Triplet(int a, int b, int c) {
        val = a;
        row = b;
        col = c;
    }
};

class myComparator {
public:
    int operator() (const Triplet &t1, const Triplet &t2) {
        return t1.val > t2.val;
    }
};

vector<int> sortedMatrix(vector<vector<int>> &mat, int n) {
    vector<int> ans;

    priority_queue<Triplet, vector<Triplet>, myComparator> pq;

    // Add first column in the priority queue.
    for(int i = 0; i < n; i++) {
        pq.push(Triplet(mat[i][0], i, 0));
    }

    // Remove the element from the queue.
    while(!pq.empty()) {

        Triplet x = pq.top();
        pq.pop();

        ans.push_back(x.val);
        int currRow = x.row;
        int currCol = x.col;

        // Add the next element from the same column of minimum extracted element.
        if(x.col < n - 1) {
            pq.push(Triplet(mat[currRow][currCol + 1], currRow, currCol + 1));
        }

    }

    return ans;
}

//Approach 2;

class Solution {
  public:
    bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
    return v1[1] < v2[1];
    }
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> ans;
       
       for(int i=0;i<N;i++){
           for(int j=0;j<N;j++){
               ans.push_back(Mat[i][j]);
           }
       }
       
       sort(ans.begin(),ans.end());
       
       int x=0;
       
       vector<vector<int>> result(N);
       for(int i=0;i<N;i++){
           result[i].assign(N,0);
           for(int j=0;j<N;j++){
               result[i][j] = ans[x++];
           }
       }
       
       return result;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> v(n,vector<int> (n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>v[i][j];
            }
        }
        Solution ob;
        v = ob.sortedMatrix(n,v);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cout<<v[i][j]<<" ";
            cout<<endl;
        }
    }
}