#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
          int rows = matrix.size();
        int cols = matrix[0].size();
        int k = 0;
        vector<int> a;
        for(int i=rows-1;i>=0;i--)
            for(int j=0;j<cols;j++)
                a.push_back(matrix[i][j]);
                
        for(int i=0;i<cols;i++)
            for(int j=0;j<rows;j++)
                matrix[j][i] = a[k++];
    }
};