#include<bits/stdc++.h>
using namespace std;
/*
    Time Complexity : O(N)
    Space Complexity : O(N)
    
    where 'N' is the number of nodes in the tree.
    
*/

// #include <unordered_map>
struct node {
  int data;
  struct node * left, * right;
};

void inorder(node *root, unordered_map<int, vector<int>> &m)
{
    if (root)
    {
        inorder(root->left, m);
        if (root->left)
        {
            m[root->data].push_back(root->left->data);
            m[root->left->data].push_back(root->data);
        }
        if (root->right)
        {
            m[root->data].push_back(root->right->data);
            m[root->right->data].push_back(root->data);
        }
        inorder(root->right, m);
    }
}

int timeToBurnTree(node *root, int start)
{
	// Initialize map to store edges and vertices.
    unordered_map<int, vector<int>> m;
    
    // Store edges by doing inorder traversal.
    inorder(root, m);
    
    // Initialize queue for bfs traversal.
    queue<int> q;
    
    q.push(start);
    
    // Variable to keep count of number of levels from start node.
    int count = 0;
    unordered_map<int, bool> visited;
    visited[start] = true;
    
    // Iterate while queue is not empty.
    while (!q.empty())
    {
        count++;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int node = q.front();
            q.pop();
            
            for(auto i:m[node])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    
    return count - 1;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  int start;
  cin>>start;
  struct node * root = newNode(1);
  root -> left = newNode(2);
//   root -> left -> right -> left = newNode(6);
//   root -> left -> right -> right = newNode(7);
  root -> right = newNode(3);
  root -> right -> left = newNode(4);
  root -> right -> right = newNode(5);

  int res;
  res = timeToBurnTree(root,start);
  cout<<res<<endl;

  return 0;
}

/*
    Time complexity : O(N)
    Space complexity : O(H)

    where 'N' is the number of nodes in the tree 
    and 'H' is the height of the tree.

*/

// class Triplet
// {
// public:
//     int max, above, below;

//     Triplet(int max, int above, int below)
//     {
//         this->max = max;
//         this->above = above;
//         this->below = below;
//     }
// };

// Triplet timeToBurnTreeHelper(BinaryTreeNode<int> *root, int start)
// {
//     if (root == NULL)
//     {
//         return Triplet(-1, -1, 0);
//     }

//     Triplet left = timeToBurnTreeHelper(root->left, start);
//     Triplet right = timeToBurnTreeHelper(root->right, start);

//     Triplet ans = Triplet(-1, -1, 0);

//     // Node is the starting node
//     if (root->data == start)
//     {
//         int below = max(left.below, right.below);
//         ans.max = below;
//         ans.above = 0;
//         ans.below = below;
//     }
    
//     // Starting Node is in left subtree
//     else if (left.above != -1)
//     {
//         ans.max = max(left.max, max(left.below, left.above + right.below + 1));
//         ans.above = left.above + 1;
//         ans.below = left.below;
//     }
    
    // Starting Node is in right subtree
    // else if (right.above != -1)
    // {
    //     ans.max = max(right.max, max(right.below, right.above + left.below + 1));
    //     ans.above = right.above + 1;
    //     ans.below = right.below;
    // }
    
    // // Starting Node doesn't exist in the subtree
    // else
    // {
    //     ans.max = -1;
    //     ans.above = -1;
    //     ans.below = max(left.below, right.below) + 1;
//     }

//     return ans;
// }

// int timeToBurnTree(BinaryTreeNode<int> *root, int start)
// {
//     Triplet ans = timeToBurnTreeHelper(root, start);
//     return ans.max;
// }

