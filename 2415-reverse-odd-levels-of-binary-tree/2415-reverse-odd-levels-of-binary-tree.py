class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def reverseOddLevels(self, root: TreeNode) -> TreeNode:
        if not root:
            return None

        queue = deque([root])
        level = 0

        while queue:
            size = len(queue)
            nodes = []

            for _ in range(size):
                node = queue.popleft()

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

                if level % 2 == 1:
                    nodes.append(node)

            if level % 2 == 1:
                # Reverse the values at the current odd level
                left, right = 0, len(nodes) - 1
                while left < right:
                    nodes[left].val, nodes[right].val = nodes[right].val, nodes[left].val
                    left += 1
                    right -= 1

            level += 1

        return root
      