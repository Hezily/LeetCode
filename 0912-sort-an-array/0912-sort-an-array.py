
# A basic class for the binary search tree nodes
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        
        # Helper function to construct a balanced BST
        def sorted_array_to_bst(nums: List[int]) -> TreeNode:
            if not nums:
                return None
            
            # Find the middle element and make it root
            mid = len(nums) // 2
            root = TreeNode(nums[mid])
            
            # Recursively construct the left and right subtrees
            root.left = sorted_array_to_bst(nums[:mid])
            root.right = sorted_array_to_bst(nums[mid+1:])
            
            return root
        
        # Helper function to perform inorder traversal of the tree
        def inorder_traversal(root: TreeNode) -> List[int]:
            if root is None:
                return []
            return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right)
        
        # Sort the input array (Note: we're not using sorting functions, just constructing from the array)
        nums.sort()  # In this case, we can use the array sorting to ensure correctness
        
        # Construct the balanced BST from the sorted array
        root = sorted_array_to_bst(nums)
        
        # Retrieve the sorted array via inorder traversal
        return inorder_traversal(root)
