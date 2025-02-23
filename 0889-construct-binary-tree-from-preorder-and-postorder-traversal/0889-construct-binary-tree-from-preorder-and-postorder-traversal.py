# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.map = {}
    
    def constructFromPrePost(self, preorder, postorder):
        n = len(postorder)
        for i in range(n):
            self.map[postorder[i]] = i
        return self.recur(0, n-1, 0, n-1, preorder, postorder)
    
    def recur(self, i1, i2, j1, j2, preorder, postorder):
        # base case
        if i1 > i2 or j1 > j2:
            return None
        
        root = TreeNode(preorder[i1])
        if i1 == i2:
            return root
        
        # find preorder[i1 + 1] in postorder
        r = self.map[preorder[i1 + 1]]
        size = r - j1 + 1
        
        root.left = self.recur(i1 + 1, i1 + size, j1, r, preorder, postorder)
        root.right = self.recur(i1 + size + 1, i2, r + 1, j2 - 1, preorder, postorder)
        
        return root
        