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
    int ret = INT_MIN;
    int dfs(TreeNode *node)
    {
        if(node==nullptr)
            return 0;
        int left = max(dfs(node->left), 0);     //9
        int right = max(dfs(node->right), 0);       //
        int value = node->val + left + right;
        ret = max(value, ret);
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ret;
    }
};
