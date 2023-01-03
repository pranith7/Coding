#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 /*
    This is an implementation of a function that recovers a binary search tree (BST) whose nodes have been swapped. 
    A BST is a type of binary tree in which the value of each node is greater than the values of its left child 
    and less than the values of its right child.

    The recoverTree function is the public interface of the solution. It takes a pointer to the root node of the
    BST as input and does not return anything.

    The recoverTree function calls the markTree function, which is a private helper function that marks the two 
    nodes whose values need to be swapped in order to recover the BST. The markTree function takes four arguments:

    root: a pointer to the root node of the BST.
    prev: a reference to a pointer to a TreeNode, which is used to keep track of the previous node during an in-order traversal of the BST.
    first: a reference to a pointer to a TreeNode, which will be set to the first node whose value needs to be swapped.
    end: a reference to a pointer to a TreeNode, which will be set to the second node whose value needs to be swapped.

    The markTree function performs an in-order traversal of the BST and compares the value of each node with the
    value of its predecessor. If it finds a pair of nodes whose values are out of order, it sets first to the 
    predecessor and end to the current node.

    Finally, the recoverTree function swaps the values of the first and end nodes and returns.
 */

class Solution {
private:
    void markTree(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end) {
        if (!root) return;
        markTree(root->left, prev, first, end);
        if (prev) {
            if (root->val < prev->val) {
                if (!first) {
                    first = prev;
                }
                end = root;
            }
        }
        prev = root;
        markTree(root->right, prev, first, end);
    }
    
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *end = nullptr;
        markTree(root, prev, first, end);
        swap(first->val, end->val);
        return;
    }
};