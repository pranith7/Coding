//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/*
    This implementation will traverse the tree and check the BST properties for each subtree. 
    If a subtree is a BST, it will return the size of that subtree. If a subtree is not a BST, 
    it will return the maximum size of its left and right subtrees. The largestBst function will 
    return the maximum size of all the BST subtrees in the tree.
*/
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root){
        if (root == NULL)
        {
            return 0;
        }
    
        // check if current subtree is a BST
        bool isBst = checkBst(root);
    
        // if current subtree is a BST, return its size
        if (isBst)
        {
            return getSize(root);
        }
    
        // if current subtree is not a BST, return the maximum size of its left and right subtrees
        return max(largestBst(root->left), largestBst(root->right));
    }
    
    // helper function to determine if a subtree is a BST
    bool checkBst(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }
    
        // check if root's value is greater than the maximum value in its left subtree
        // and less than the minimum value in its right subtree
        bool isBst = (root->data > getMax(root->left)) && (root->data < getMin(root->right));
    
        // check recursively if left and right subtrees are BSTs
        return isBst && checkBst(root->left) && checkBst(root->right);
    }
    
    // helper function to get the size of a subtree
    int getSize(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
    
        return 1 + getSize(root->left) + getSize(root->right);
    }
    
    // helper function to get the maximum value in a subtree
    int getMax(Node *root)
    {
        if (root == NULL)
        {
            return INT_MIN;
        }
    
        return max(root->data, max(getMax(root->left), getMax(root->right)));
    }
    
    // helper function to get the minimum value in a subtree
    int getMin(Node *root)
    {
        if (root == NULL)
        {
            return INT_MAX;
        }
    
        return min(root->data, min(getMin(root->left), getMin(root->right)));
    }

};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends