#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N+M+K)
    Space Complexity: O(1)

    where N, M and K denotes the number of elements in the array A, B and C respectively.
*/

vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    // Getting the size of each array
    int n = a.size();
    int m = b.size();
    int k = c.size();
    // Defining the vector to store common elements
    vector<int> ans;
    // Setting the pointer variables
    int p = 0, q = 0, r = 0;
    // Iterating through the first array
    while (p < n)
    {
        // Moving the pointer to second array ahead until it attains value which is not smaller than current element of first array
        while (q < m && b[q] < a[p])
        {
            q++;
        }
        // Checking if we completely traversed second array
        if (q == m)
        {
            break;
        }
        // Moving the pointer to third array ahead until it attains value not which is smaller than current element of first array
        while (r < k && c[r] < a[p])
        {
            r++;
        }
        // Checking if we completely traversed third array
        if (r == k)
        {
            break;
        }
        if (a[p] == b[q] && a[p] == c[r])
        {
            if (ans.size() == 0 || ans[ans.size() - 1] != a[p])
            {
                ans.push_back(a[p]);
            }
        }
        // Moving the pointer to first array ahead
        p++;
    }
    return ans;
}

vector<int> solve(vector<int> &a,vector<int> &b, vector<int> &c)
{


// Write your code here
    map<int,int> mp;
    int n = a.size();
    int m = b.size();
    int p = c.size();
    for(int i:a) mp[i]++;
    for(int j:b) mp[j]++;
    for(int k:c) mp[k]++;
    vector<int> ans;
    for(auto i:mp)
    {
        if(i.second == 3)
        {
            ans.push_back(i.first);
        }
    }
    
    return ans;
}

int main()
{   
    int n,m,o;
    cin>>n>>m>>o;
    vector<int> a(n),b(m),c(o);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<o;i++)
    {
        cin>>c[i];
    }
    vector<int> ans = findCommonElements(a, b, c);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}