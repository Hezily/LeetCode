from typing import Optional

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = None
#         self.right = None

class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        self.index = 0  # Keeps track of the current position in the traversal string
        n = len(traversal)

        def dfs(depth: int) -> Optional[TreeNode]:
            start = self.index
            dash_count = 0
            
            # Count dashes to determine depth
            while self.index < n and traversal[self.index] == '-':
                dash_count += 1
                self.index += 1
            
            # If depth doesn't match, backtrack
            if dash_count != depth:
                self.index = start
                return None
            
            # Read the node's value
            num = 0
            while self.index < n and traversal[self.index].isdigit():
                num = num * 10 + int(traversal[self.index])
                self.index += 1
            
            # Create the node
            node = TreeNode(num)
            node.left = dfs(depth + 1)
            node.right = dfs(depth + 1)
            return node

        return dfs(0)
