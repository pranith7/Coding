#include<bits/stdc++.h>
using namespace std;

/*
The function permute generates all permutations of the input array arr of size n. It does this by using 
a frequency array freq to keep track of which elements have been used in the current permutation. The 
function takes in a vector temp which stores the current permutation being generated, and a vector result
which stores all the permutations generated so far.

The function first checks if the size of temp is equal to n, in which case it means that all elements of
arr have been used and the current permutation is complete. In this case, the current permutation is added
to result and the function returns.

If the size of temp is less than n, the function iterates through all the elements of arr and checks if the
 element has already been used (by checking if freq[i] is 0). If the element has not been used, it 
adds it to temp, sets freq[i] to 1 to mark it as used, and calls the function recursively. After the recursive call returns, it
sets freq[i] back to 0 and removes the element from temp. This process is repeated until all permutations have been generated.

The solve function simply initializes the frequency array and calls permute. It returns the result vector
which contains all permutations of arr.
*/

void permute(int arr[], int n, int freq[],vector<int> &temp,vector<vector<int>> &result)
{
    if(temp.size() == n) 
    {
        result.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!freq[i])
        {
            temp.push_back(arr[i]);
            freq[i] = 1;
            permute(arr,n,freq,temp,result);
            freq[i] = 0;
            temp.pop_back();
        }
    }
    
}

vector<vector<int>> solve(int arr[],int n)
{
    vector<vector<int>> result;
    vector<int> temp;
    int freq[n] = {0};
    for(int i = 0; i < n; i++) freq[i] = 0;
    permute(arr,n,freq,temp,result);
    return result;
}

int main()
{   
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>> ans = solve(arr,n);
    cout<<"Permutations of the given array are as follows:"<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}