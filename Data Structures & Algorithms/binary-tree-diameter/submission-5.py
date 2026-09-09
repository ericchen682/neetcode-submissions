# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def helper(self, root: Optional[TreeNode]) -> Tuple[int, int]:
        if root is None:
            return (0, 0)
        lmax, ldepth = self.helper(root.left)
        rmax, rdepth = self.helper(root.right)
        depth = max(ldepth, rdepth) + 1
        res = max(lmax, rmax, ldepth + rdepth + 1)
        return (res, depth)
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # diameter of a binary tree is max(left, right, maxdepth left + maxdepth right)
        res, depth = self.helper(root)
        return res - 1