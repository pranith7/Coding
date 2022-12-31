#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

    /*
        The setZeroes function is a member function of the Solution class that takes a two-dimensional 
        vector of integers called matrix as input, and sets all the elements in the matrix to 0 if they
        are located in the same row or column as an element with value 0.

        The function first declares the variables col0, rows, and cols, which represent the first column 
        of the matrix, the number of rows in the matrix, and the number of columns in the matrix, 
        respectively.

        It then enters a loop that iterates over the rows of the matrix. For each row, it checks if the 
        first element of the row has a value of 0. If this is the case, it sets the value of col0 to 0. 
        It then enters another loop that iterates over the elements of the row, starting from the second 
        element. If it encounters an element with a value of 0, it sets the value of the first element of
         the row and the element in the first column of the same row to 0.

        The function then enters another loop that iterates over the rows of the matrix in reverse order. 
        For each row, it enters a loop that iterates over the elements of the row in reverse order, 
        starting from the second to the last element. If it finds an element whose value in the first 
        column or the first element of the row is 0, it sets the value of the element to 0. Finally, 
        if the value of col0 is 0, it sets the value of the first element of the row to 0.
    */
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
    }
};