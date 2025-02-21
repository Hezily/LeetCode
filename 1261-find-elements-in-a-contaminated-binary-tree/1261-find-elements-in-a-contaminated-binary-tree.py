# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.set = set()
        self.dfs(root, 0)

    def find(self, target: int) -> bool:
        return target in self.set

    def dfs(self, root: Optional[TreeNode], val: int):
        if not root:
            return
        root.val = val
        self.set.add(val)
        self.dfs(root.left, 2 * val + 1)
        self.dfs(root.right, 2 * val + 2)
# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
