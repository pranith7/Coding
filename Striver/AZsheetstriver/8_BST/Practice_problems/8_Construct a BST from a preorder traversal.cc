#include<bits/stdc++.h>
using namespace std;


//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution { //Reursion
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)
            return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        if(preorder.size()==1)
            return root;
        vector<int>left;
        vector<int>right;
        for(int i=0;i<preorder.size();i++)
        {
            if(preorder[i]>preorder[0])
                right.push_back(preorder[i]);
            else if(preorder[i]<preorder[0])
                left.push_back(preorder[i]);
        }
        root->left=bstFromPreorder(left);
        root->right=bstFromPreorder(right);
        return root;
    }
};


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0){  // If vector is empty, return NULL
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[0]); // Tree will start off with vector's first value;
        
        for (int i = 1; i < preorder.size(); i++){  // Traversing the vector
            bool done = false;  // Marker to indicate when the vector value has been added to the tree
            TreeNode* current = root;   // Current is used to traverse the tree we're creating
            
            while (done == false){
                if (preorder[i] < current->val){    // If the vector value is less than the current tree node's value
                    if (current->left == NULL){ // Add the vector value to the tree if there is an available spot
                        current->left = new TreeNode(preorder[i]);
                        done = true;    // Vector value has been added, therefore done = true and break out of while loop
                    }
                    else{   // If there's no available spot, keep traversing our tree
                        current = current->left;
                    }
                }
                else{   // If vector value is greater than current tree node's value
                    if (current->right == NULL){ // Add the vector value to tree if spot is available
                        current->right = new TreeNode(preorder[i]);
                        done = true; // Vector value added, therefore break out of while loop
                    }
                    else{
                        current = current->right;   // No spot available, keep traversing tree
                    }
                }
            }
        }
        
        return root;
    }
};