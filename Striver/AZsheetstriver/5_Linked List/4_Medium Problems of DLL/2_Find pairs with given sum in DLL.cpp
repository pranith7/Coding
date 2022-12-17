//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node *ptr1 = head, *ptr2 = head;
        while (ptr2->next)
        {
            ptr2 = ptr2->next;
        }
        vector<pair<int, int>> res;
        while (ptr1 != ptr2 && ptr2->next != ptr1)
        {
            int sum = ptr1->data + ptr2->data;

            if (sum == target)
            {
                res.push_back(make_pair(ptr1->data, ptr2->data));
                ptr1 = ptr1->next;
                ptr2 = ptr2->prev;
            }
            else if (sum < target)
            {
                ptr1 = ptr1->next;
            }
            else
            {
                ptr2 = ptr2->prev;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends