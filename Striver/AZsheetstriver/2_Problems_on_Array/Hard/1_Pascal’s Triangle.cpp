#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //pascals traingle
        /*
            The generate function is a member function of the Solution class that generates 
            a two-dimensional vector of integers representing a "Pascal's Triangle" with a 
            given number of rows.

            The function takes an integer numRows as input and returns a two-dimensional vector 
            of integers ans. It then enters a loop that iterates numRows times. In each iteration,
            it creates a vector rows with i+1 elements, all initialized to 1. It then enters another
            loop that iterates from 1 to i-1. In each iteration, it sets the value of the element at
            index j in rows to the sum of the elements at indices j-1 and j in the previous row of ans.
            After the inner loop finishes, it pushes the current row rows into the ans vector.

            Finally, the function returns the ans vector.
        */
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++)
        {
            vector<int> rows(i+1,1);
            for(int j=1;j<i;j++)
            {
                rows[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(rows);
        }
        return ans;
    }
};