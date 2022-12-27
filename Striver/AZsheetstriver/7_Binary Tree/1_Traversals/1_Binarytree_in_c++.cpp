/*
    Full binary tree: -> Either has two or zero children
    Complete Binary tree: -> 1. All levels are completely filled except the last level
                             2. the last level has all nodels in left as possible
    Perfect binary tree: ->  All leaf nodes are at the same level.
    Balanced binary tree: -> height of tree at max log(n)
    Degenerate tree : skew trees

*/
#include<bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    cout<<root->left->right->data;
    
    return 0;
}


