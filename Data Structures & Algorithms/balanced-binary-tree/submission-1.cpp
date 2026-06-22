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
    pair<bool, int> isBalancedDepth(TreeNode* root)
    {
        if(root == nullptr)
            return { true, 0 };
        auto [ bl, dl ] = isBalancedDepth(root->left);
        auto [ br, dr ] = isBalancedDepth(root->right);
        if (bl && br && abs(dl - dr) <= 1)
            return { true, max(dl, dr) + 1 };
        return { false, max(dl, dr) + 1 };
    }

    bool isBalanced(TreeNode* root) {
        // find depth of left and right subtree and then determine if they are balanced
        // also determine if left node and right node are height-balanced
        return isBalancedDepth(root).first;
    }
};
