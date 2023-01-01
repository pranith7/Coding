#include<bits/stdc++.h>
using namespace std;

/*
        This function tries to solve a Sudoku puzzle represented by a 2D vector board. The function uses
        backtracking to find a solution.

        The function first checks if the current cell is empty. If it is empty, it tries to fill the cell
        with a character from '1' to '9'. For each character, it checks if it is a valid move by calling 
        the isvalid function. If the move is valid, it fills the cell with the character and recursively 
        calls itself on the next cell. If the recursive call returns true, it means the Sudoku puzzle has
        been solved and the function returns true. If the recursive call returns false, it means the 
        current character does not lead to a solution and the function tries the next character. If all
        characters have been tried and none of them lead to a solution, the function returns false and 
        backtracks to the previous cell. If the current cell is not empty, the function moves on to the
        next cell. If all cells have been filled and the function has not returned false, it means the 
        Sudoku puzzle has been solved and the function returns true.
*/

bool isvalid(vector<vector<char>> &board,int row,int col,char c)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col] == c) return false;

        if(board[row][i] == c) return false;

        if(board[3*(row)/3 + i/3][3*(col/3)+i%3] == c) return false;

    }

    return true;
}

bool solve(vector<vector<char>>&board)
{   
    for(int i=0;i<board.size();i++) 
    {   
        for(int j=0;j<board[0].size();j++) 
        {
            if(board[i][j] = '.') //check it is an empty cell
            {
                for(char c = '1';c <= '9';c++)
                {   
                    if(isvalid(board,i,j,c))
                    {
                        board[i][j] = c;
                        if(solve(board) == true)
                            return true;
                        else
                            board[i][j] = '.';
                    }

                }
             return false;
            }
        }
    }
    return true;
}


void solvesudoku(vector<vector<char>> &board)
{
    solve(board);
}


int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solvesudoku(board);
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}