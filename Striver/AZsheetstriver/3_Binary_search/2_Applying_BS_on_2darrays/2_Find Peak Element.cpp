#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    /*
        This is a class that defines a solution to the problem of finding the peak element in a matrix 
        of integers. A peak element is defined as an element that is greater than or equal to all its 
        neighbors.

        The class has a single public method called findPeakGrid that takes in a single parameter:

        mat: a 2D vector of integers representing the matrix
        The method returns a vector of two integers representing the row and column indices of the
         peak element.

        The method initializes two variables startCol and endCol to the first and last column indices 
        of the matrix respectively. It then enters a loop that continues until startCol is no longer 
        less than or equal to endCol.

        In each iteration of the loop, the method calculates the middle column index (midCol) and finds 
        the row index of the maximum element in this column (maxRow). The method then checks if the element 
        at maxRow, midCol has any neighbors that are greater than it. If it does not, the method returns the 
        indices of this element. If the element to the left is greater, the method updates endCol to midCol 
        minus one and continues to the next iteration. If the element to the right is greater, the method 
        updates startCol to midCol plus one and continues to the next iteration.

        If the loop completes without finding a peak element, the method returns a vector containing -1 
        for both indices.
    */
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int startCol = 0, endCol = mat[0].size()-1;
        
        while(startCol <= endCol){
            int maxRow = 0, midCol = startCol + (endCol-startCol)/2;
            
            for(int row=0; row<mat.size(); row++){
                maxRow = mat[row][midCol] >= mat[maxRow][midCol]? row : maxRow;   
            }
            
            bool leftIsBig    =   midCol-1 >= startCol  &&  mat[maxRow][midCol-1] > mat[maxRow][midCol];
            bool rightIsBig   =   midCol+1 <= endCol    &&  mat[maxRow][midCol+1] > mat[maxRow][midCol];
            
            if(!leftIsBig && !rightIsBig)          // we have found the peak element
                return vector<int>{ maxRow, midCol};
            
            else if(rightIsBig) // if rightIsBig, then there is an element in 'right' that is bigger than all the elements in the 'midCol', 
                startCol = midCol+1;    //so 'midCol' cannot have a 'peakPlane'
            
            else // leftIsBig
                endCol = midCol-1;
        }
        return vector<int>{-1,-1}; 
    }
};