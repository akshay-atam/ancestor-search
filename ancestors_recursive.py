# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Recursive function to print all ancestors of a given node in a binary tree.
# The function returns true if the node is found in the subtree rooted at the
# given root node.
def printAncestors(root, node):
 
    # base case
    if root is None:
        return False
 
    # return true if a given node is found
    if root.data == node:
        return True
 
    # search node in the left subtree
    left = printAncestors(root.left, node)
 
    # search node in the right subtree
    right = False
    if not left:
        right = printAncestors(root.right, node)
 
    # if the given node is found in either left or right subtree,
    # the current node is an ancestor of a given node
    if left or right:
        print(root.data, end=' ')
 
    # return true if a node is found
    return left or right

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