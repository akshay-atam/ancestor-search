from collections import deque
 
 
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Function to print root-to-leaf paths without using recursion
def printTopToBottomPath(parent, key):
 
    while key:
        print(key, end=' ')
        key = parent[key]
 
 
# Iterative function to set parent nodes for all nodes of the binary tree
# in a given dict. The function is similar to the iterative preorder traversal
def setParent(root, parent):
 
    # create an empty stack and push the root node
    stack = deque()
    stack.append(root)
 
    # loop till stack is empty
    while stack:
        # Pop the top item from the stack
        curr = stack.pop()
 
        # push its right child into the stack and set its parent on the dictionary
        if curr.right:
            parent[curr.right.data] = curr.data
            stack.append(curr.right)
 
        # push its left child into the stack and set its parent on the dictionary
        if curr.left:
            parent[curr.left.data] = curr.data
            stack.append(curr.left)
 
 
# Iterative function to print all ancestors of a given node in a binary tree
def printAncestors(root, node):
 
    # base case
    if root is None:
        return
 
    # create an empty dictionary to store parent pointers of binary tree nodes.
    # set the parent of the root node as 0
    parent = {root.data: 0}
 
    # set parent nodes for all nodes of the binary tree
    setParent(root, parent)
 
    # print ancestors of a given node using the parent dictionary
    printTopToBottomPath(parent, parent[node])
 
 
if __name__ == '__main__':
 
    ''' Construct the following tree
         3
       /   \
      /     \
     5       1
    / \     / \
   6   2   0   8
      / \
     7   4
    '''

    root = Node(3)
    root.left = Node(5)
    root.right = Node(1)
    root.left.left = Node(6)
    root.left.right = Node(2)
    root.right.left = Node(0)
    root.right.right = Node(8)
    root.left.right.left = Node(7)
    root.left.right.right = Node(4)
 
    node = 8
    printAncestors(root, node)