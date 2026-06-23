/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // max of left subtree depth + right subtree depth
    int res = 0;
    int helper(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        // set res to left depth + right depth + 1
        res = max(res, left + right + 1);

        // returns max depth
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return res - 1;
    }
};
