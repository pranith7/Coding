#include<bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class BSTIterator {
public:
    /*
        This is the constructor of the BSTIterator class. It takes as input a pointer to the root 
        node of the BST and initializes the iterator to the smallest element in the BST. It does 
        this by initializing the cur pointer to the root node and pushing the nodes in the in-order
        traversal of the BST to a stack stk. The cur pointer is used to keep track of the current 
        node in the in-order traversal, and the stk stack is used to store the nodes that have been 
        visited in the in-order traversal. The cur pointer is moved to the left child of the current 
        node until it reaches a leaf node (a node with no children). This process is repeated for 
        each left child of a node in the in-order traversal, so that the nodes in the in-order 
        traversal are added to the stack in the correct order.
    */
    BSTIterator(TreeNode* root) {
         // Initialize the stack with the nodes in the in-order traversal of the BST
        cur = root;
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
    }
    /*
        The hasNext function returns a boolean value indicating whether there is a next smallest 
        element in the BST. It does this by returning true if the stk stack is non-empty and false
        otherwise.

        The BSTIterator class also has two private member variables: stk, a stack of TreeNode* 
        pointers used to store the nodes in the in-order traversal of the BST, and cur, a TreeNode* pointer used to 
        keep track of the current node in the in-order traversal. These member variables are used to implement the next and hasNext functions.

        To use the BST iterator, you can instantiate an object of the BSTIterator class and call its next and hasNext functions as follows:
    */
    int next() {
         // Pop the top element from the stack and move to its right child
        cur = stk.top();
        stk.pop();
        int val = cur->val;
        cur = cur->right;
        
        // Push the left children of the current node to the stack
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        
        return val;
    }
    /*
        The next function returns the next smallest element in the BST and advances the iterator to the next element. The
        hasNext function returns a boolean value indicating whether there is a next element in the BST. You can use these 
        functions to iterate through the elements of the BST in ascending order.

        For example, the following code prints the elements of the BST in ascending order:
    */
    bool hasNext() {
         return !stk.empty();
    }
private:
    std::stack<TreeNode*> stk;
    TreeNode* cur;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */