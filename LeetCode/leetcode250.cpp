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
    int count;
    bool dfs(TreeNode *node, int val)
    {
        if(!node)
            return true;
        bool left = dfs(node->left, node->val==val?val:node->val);
        bool right = dfs(node->right, node->val==val?val:node->val);
        if(left && right)
            ++count;
        return node->val==val && left && right;
    }

    int countUnivalSubtrees(TreeNode* root) {
        count = 0;
        if(!root)
            return 0;
        dfs(root, root->val);
        return count;
    }
};
