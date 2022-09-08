#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N*M)
    Space Complexity: O(M)
    
    Where 'N' and 'M' denotes the number of rows 
    and the number of columns in the matrix respectively.
*/


vector<int> findCommonElements(vector<vector<int>> &mat)
{
    // Finding the number of rows and columns
    int n = mat.size();
    int m = mat[0].size();

    // Defining the HashMap to store common elements
    unordered_map<int, int> commonElements;

    // Adding the elements of first row to HashMap
    for (int j = 0; j < m; j++)
    {
        commonElements[mat[0][j]] = 1;
    }

    // Iterating through the elements of the matrix
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Checking whether the current element is present in all the previously traversed rows
            if (commonElements.find(mat[i][j]) != commonElements.end() && commonElements[mat[i][j]] == i)
            {
                commonElements[mat[i][j]]++;
            }
        }
    }

    // Defining the output array
    vector<int> ans;

    // Traversing the HashMap
    for (pair<int, int> p : commonElements)
    {
        // Adding all elements that are present in all the matrix rows to the output array
        if (p.second == n)
        {
            ans.push_back(p.first);
        }
    }

    // Returning the output array
    return ans;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    }


    vector<int> ans;
    ans = findCommonElements(mat);
    
    
    cout<<"Output is "<<endl;

    for(int i=0;i<ans.size();i++) 
        cout<<ans[i]<<" ";

    return 0;
}
