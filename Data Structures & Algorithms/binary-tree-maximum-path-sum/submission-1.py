# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def helper(self, root: Optional[TreeNode]) -> Tuple[int, int]:
        if root is None:
            return [-1001, -1001]
        left, left_root = self.helper(root.left)
        right, right_root = self.helper(root.right)
        res = max(left, right, root.val + max(0, left_root) + max(0, right_root))
        max_path = root.val + max(left_root, right_root, 0)
        return [res, max_path]

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        return self.helper(root)[0]