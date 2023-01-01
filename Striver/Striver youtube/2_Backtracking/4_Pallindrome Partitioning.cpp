#include<bits/stdc++.h>
using namespace std;

/*
    This function returns all the possible partitions of the given string s into substrings such that
    each substring is a palindrome.

    The function works by using a backtracking approach. It has an inner function func that takes in 
    the index of the current position in the string, the string itself, a vector path to store the 
    current partition, and a vector res to store all the possible partitions. It works as follows:

    If the index is equal to the size of the string, that means we have reached the end of the string
    and we have found a valid partition. The function adds the current path to the res vector and returns.

    Otherwise, the function tries all possible substrings starting from the current index and ending at
    different points in the string. For each substring, it checks if it is a palindrome using the 
    isPalindrome function. If the substring is a palindrome, it adds it to the path vector and calls
    the func function again with an updated index and path. Once the recursive call returns, it removes
     the last element from the path vector to backtrack and try different substrings.

    Finally, the partition function returns the res vector containing all the possible partitions.
*/
bool isPalindrome(string s,int start,int end)
{
    while(start<=end)
    {
        if(s[start++]!=s[end--])
        {
            return false;
        }

    }
    return true;
}

void func(int index,string s,vector<string> &path,vector<vector<string>> &res)
{
    if(index == s.size())
    {
        res.push_back(path);
        return;

    }
    for(int i=index;i<s.size();i++)
    {
        if(isPalindrome(s,index,i))
        {
            path.push_back(s.substr(index,i-index+1));
            func(i+1,s,path,res);
            path.pop_back();
        }
    }

}


vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> path;

    func(0,s,path,result);
    return result;

}
 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<vector<string>> ans;
        ans = partition(s);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}