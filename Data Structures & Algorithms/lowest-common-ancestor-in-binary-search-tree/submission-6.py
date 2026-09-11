# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, r: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if p.val < q.val:
            p, q = q, p
        if r.val == p.val or r.val == q.val:
            return r
        if r.val < p.val and r.val > q.val:
            return r
        if r.val < q.val:
            return self.lowestCommonAncestor(r.right, p, q)
        return self.lowestCommonAncestor(r.left, p, q)