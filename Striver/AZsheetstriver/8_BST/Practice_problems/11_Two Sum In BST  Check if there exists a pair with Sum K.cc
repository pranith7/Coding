#include<bits/stdc++.h>
using namespace std;

/*
    This is a C++ implementation of a function that checks whether there are two nodes in a binary 
    search tree (BST) whose sum is equal to a given target value k. The function performs an in-order
    traversal of the BST and uses a hash set to store the values of the nodes that have been visited. 
    As it visits each node, it checks whether k - cur->val is present in the hash set. If it is, then
    there is a pair of nodes whose sum is equal to k, and the function returns true. If the function
    reaches the end of the in-order traversal and has not found such a pair of nodes, it returns false.

    The function takes as input a pointer to the root node of the BST (root) and the target value k,
    and it returns a boolean value indicating whether there are two nodes in the BST whose sum is 
    equal to k.

    The TreeNode struct represents a node in the BST, with fields val, left, and right for the value 
    stored at the node, and pointers to the left and right children of the node. The TreeNode struct 
    has three constructors: one that initializes a node with no arguments, one that initializes a node
    with a value x, and one that initializes a node with a value x, a left child left, and a right 
    child right. The Solution class contains the findTarget function.
*/

//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
  // Create a hash set to store the values of the nodes that have been visited
  std::unordered_set<int> visited;

  // Create a stack to store the nodes in the in-order traversal
  std::stack<TreeNode*> stk;

  // Initialize the current node to the root node
  TreeNode* cur = root;

  // Perform an in-order traversal of the BST
  while (cur || !stk.empty()) {
    // Go to the leftmost child of the current node
    while (cur) {
      stk.push(cur);
      cur = cur->left;
    }

    // Visit the top node on the stack
    cur = stk.top();
    stk.pop();

    // Check if the value `k - cur->val` is present in the hash set
    if (visited.count(k - cur->val) > 0) {
      return true;
    }

    // Add the value of the current node to the hash set
    visited.insert(cur->val);

    // Move to the right child of the current node
    cur = cur->right;
  }

  // Return false if a pair of nodes whose sum is equal to `k` was not found
  return false;
}

};

