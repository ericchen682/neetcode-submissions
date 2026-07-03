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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // its a bst
        while(root != p && root != q)
        {
            // p on right
            if(root->val < p->val)
            {
                // q on left
                if(root->val > q->val)
                {
                    return root;
                }
                // q on right
                root = root->right;
            }
            // p on left
            else
            {
                // q on right
                if(root->val < q->val)
                {
                    return root;
                }
                // q on left
                root = root->left;
            }
        }
        return root;
    }
};
