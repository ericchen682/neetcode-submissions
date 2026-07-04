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
    tuple<bool, int, int> solve(TreeNode* root)
    {
        if(root == nullptr) return {true, INT_MIN, INT_MAX};
        auto [lst, lmax, lmin] = solve(root->left);
        auto [rst, rmax, rmin] = solve(root->right);
        if(!lst || !rst) return {false, INT_MIN, INT_MAX};
        if(lmax >= root->val) return {false, INT_MIN, INT_MAX};
        if(rmin <= root->val) return {false, INT_MIN, INT_MAX};
        return {true, max(rmax, root->val), min(lmin, root->val)};
    }

    bool isValidBST(TreeNode* root) {
        // find max node of left tree
        // find min node of right tree
        // recurisvely
        auto [res, rmin, rmax] = solve(root);
        return res;
    }
};
