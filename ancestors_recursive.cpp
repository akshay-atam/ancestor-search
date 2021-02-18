// O(n) time | O(k) space
// where n is the number of nodes in a binary tree and
// h is the height of the binary tree required for the call stack

#include <iostream>

using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to print all ancestors of a given node in a binary tree.
// The function returns true if the node is found in the subtree rooted at the
// given root node.
bool printAncestors(Node *root, int node)
{
    // if tree is empty
    if (root == nullptr) {
        return false;
    }
 
    // TRUE if given node found
    if (root->data == node) {
        return true;
    }
 
    // search node in left subtree
    bool left = printAncestors(root->left, node);
 
    // search node in right subtree
    bool right = false;
    if (!left) {
        right = printAncestors(root->right, node);
    }
 
    // if given node found in either left or right subtree,
    // then current node is ancestor of a given node
    if (left || right) {
        cout << root->data << " ";
    }
 
    // if a node is found, return TRUE
    return left || right;
}
 
int main()
{
    Node* root = nullptr;
 
    /* map of the binary tree in question
         3
       /   \
      /     \
     5       1
    / \     / \
   6   2   0   8
      / \
     7   4
    */
 
    root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
 
    int node = 8;
    printAncestors(root, node); // prints 1 3 as output
 
    return 0;
}