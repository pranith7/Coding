#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    where ‘N’ is the side length of the given square matrix.
*/

void transpose(vector<vector<int>> &inputArray)
{
    for (int i = 0; i < inputArray[0].size(); i++)
    {
        for (int j = i; j < inputArray[0].size(); j++)
        {
            swap(inputArray[j][i], inputArray[i][j]);
        }
    }
}

void reverseColumns(vector<vector<int>> &inputArray)
{
    for (int i = 0; i < inputArray[0].size(); i++)
    {
        for (int j = 0, k = inputArray[0].size() - 1; j < k; j++, k--)
        {
            swap(inputArray[j][i], inputArray[k][i]);
        }
    }
}

void inplaceRotate(vector<vector<int>> &inputArray)
{
    transpose(inputArray);
    reverseColumns(inputArray);
}

int main()
{   
    int n,m;
    cin>>n>>m;
    vector<vector<int>> inputArray(n,vector<int> (m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>inputArray[i][j];
        }
    }
    cout<<"output of the Array :: "<<endl;
    for (int i = 0; i < inputArray.size(); i++)
    {
        for (int j = 0; j < inputArray[0].size(); j++)
            cout<<inputArray[i][j];
        cout<<endl;
    }
    return 0;
}