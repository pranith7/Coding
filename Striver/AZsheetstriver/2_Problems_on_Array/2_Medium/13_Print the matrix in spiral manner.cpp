#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int n = matrix.size();
    int m = matrix[0].size();
    int startrow = 0;
    int startcol = 0;
    int endrow = n-1;
    int endcol = m-1;
    
    while(startrow <= endrow and startcol <= endcol)
    {
        for(int col = startcol;col<=endcol;col++)
        {
            result.push_back(matrix[startrow][col]);
        }
        for(int row = startrow+1;row <=endrow;row++)
        {
            result.push_back(matrix[row][endcol]);
        }
        for(int col = endcol-1;col>=startcol;col--)
        {    
            if(startrow == endrow) break;
            result.push_back(matrix[endrow][col]);
        }
        for(int row = endrow -1;row>=startrow+1;row--)
        {    
            if(startcol == endcol) break;
            result.push_back(matrix[row][startcol]);
        }
        startrow++;
        startcol++;
        endrow--;
        endcol--;   
    }
    return result;
    }
};