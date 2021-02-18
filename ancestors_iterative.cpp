// O(n) time | O(n) space
// where n is the number of nodes in a binary tree

#include <iostream>
#include <stack>
#include <unordered_map>

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
 
// Function to print root-to-leaf paths without using recursion
void rootToLeaf(unordered_map<int, int> parent, int key)
{
    while (key = parent[key]) {
        cout << key << " ";
    }
 
    cout << endl;
}
 
// Iterative function to set parent nodes for all nodes of the binary tree
// in a given map. The function is similar to the iterative preorder traversal
void setParent(Node* root, unordered_map<int, int> &parent)
{
    // create an empty stack and push the root node
    stack<Node*> stack;
    stack.push(root);
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // Pop the top item from the stack
        Node* curr = stack.top();
        stack.pop();
 
        // push its right child into the stack and set its parent on the map
        if (curr->right)
        {
            parent[curr->right->data] = curr->data;
            stack.push(curr->right);
        }
 
        // push its left child into the stack and set its parent on the map
        if (curr->left)
        {
            parent[curr->left->data] = curr->data;
            stack.push(curr->left);
        }
    }
}
 
// Iterative function to print all ancestors of a given node in a binary tree
void printAncestors(Node* root, int node)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // create an empty map to store parent pointers of binary tree nodes
    unordered_map<int, int> parent;
 
    // set the parent of the root node as 0
    parent[root->data] = 0;
 
    // set parent nodes for all nodes of the binary tree
    setParent(root, parent);
 
    // print ancestors of a given node using the parent map
    rootToLeaf(parent, node);
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