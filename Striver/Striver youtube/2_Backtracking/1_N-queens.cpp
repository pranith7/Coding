#include<bits/stdc++.h>
using namespace std;



// bool issafe(int col,int row,vector<string>&board,int n)
// {
//     //check upper diagonal
//     int duprow = row;
//     int dupcol = col;

//     while(row>=0 && col>=0)
//     {
//         if(board[row][col] == 'Q')  return false;
//         row--;
//         col--;
//     }

//     //check lower diagonal
//     row = duprow;
//     col = dupcol;

//     while(row<=n && col>=0)
//     {
//         if(board[row][col] = 'Q')  return false;
//         row++;
//         col--;  
//     }

//     //check left row
//     row = duprow;
//     col = dupcol;
//     while(col>=0)
//     {
//         if(board[row][col] == 'Q') return false;
//         col--;
//     }

//     return true;
// }


// void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n)
// {
//     if(col == n)    //BaseCase
//     {
//         ans.push_back(board);
//         return;
//     }
//     for(int row=0;row<=n;row++)
//     {
//         if(issafe(row,col,board,n))
//         {
//             board[row][col] = 'Q';
//             solve(col+1,board,ans,n);
//             board[row][col] = '.';
//         }
//     }
// }


// vector<vector<string>> solveNqueens(int n)
// {
//     vector<vector<string>> ans;
//     vector<string> board(n);
//     string s(n,'.');
//     for(int i = 0; i < n; i++)
//     {
//         board[i] = s;
//     }
//     vector<int> leftrow(n,0);
//     vector<int> lowdiagonal(2*n-1,0);
//     vector<int> upperdiagonal(2*n-1,0);
//     solve(0,board,ans,n);
//     return ans;
// }

/*
    This function is a recursive function that generates all possible solutions to the N-Queens problem, 
    where N queens are placed on an NxN chessboard such that no two queens can attack each other. The 
    function takes an integer n as input, which represents the size of the chessboard. 
    
    The function has four input vectors:

    board:          a vector of strings representing the current state of the chessboard
    ans:            a vector of vectors of strings representing all the solutions found so far
    leftrow:        a vector of integers representing the state of each row on the chessboard 
                    (1 if a queen is placed on that row, 0 otherwise)
    lowdiagonal:    a vector of integers representing the state of each low diagonal on the 
                    chessboard (1 if a queen is placed on that diagonal, 0 otherwise)
    upperdiagonal:  a vector of integers representing the state of each upper diagonal on the chessboard 
                    (1 if a queen is placed on that diagonal, 0 otherwise)


    The function works by starting from the first column and trying to place a queen on each row of that column.
    If a queen can be placed on a particular row without violating the constraints (no other queen on the 
    same row, low diagonal, or upper diagonal), then the function places the queen on that row, updates 
    the state of the corresponding row, low diagonal, and upper diagonal, and then recursively calls itself 
    for the next column. If no queen can be placed on any row of the current column, the function returns 
    without adding any solution to the ans vector. If the function has placed queens on all the columns 
    (base case), it adds the current state of the board to the ans vector as a solution. The function then 
    backtracks, removes the queen placed on the current column, and updates the state of the corresponding row,
    low diagonal, and upper diagonal before returning. This process is repeated until all solutions have been found.
*/

void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftrow,
vector<int> &lowdiagonal,vector<int> &upperdiagonal,int n)
{
    if(col == n)    //BaseCase
    {
        ans.push_back(board);
        return;
    }
    for(int row=0;row<=n;row++)
    {
        if(leftrow[row] == 0 && lowdiagonal[row + col] == 0 && upperdiagonal[n-1+col-row] == 0)
        {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowdiagonal[row + col] = 1;
            upperdiagonal[n-1+col-row] = 1;
            solve(col+1,board,ans,leftrow,lowdiagonal,upperdiagonal,n);
            board[row][col] = '.';
            leftrow[row] = 0;
            lowdiagonal[row + col]= 0;
            upperdiagonal[n-1+col-row] = 0;
        }
    }
}


vector<vector<string>> solveNqueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i = 0; i < n; i++)
    {
        board[i] = s;                   //Initialize Board
    }
    vector<int> leftrow(n,0);           //Creating leftrow vector
    vector<int> lowdiagonal(2*n-1,0);   //Creating lowdiagonal vector
    vector<int> upperdiagonal(2*n-1,0); //Creating upperdiagonal vector
    solve(0,board,ans,leftrow,lowdiagonal,upperdiagonal,n);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans;
    ans = solveNqueens(n);
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n;j++)
     {
        cout << ans[i][j]<<" ";
     }
     cout << endl;
    }
    return 0;
}
//Approach - 2



