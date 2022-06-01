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

    int dfs(TreeNode *node, int p)
    {
        if(!node)
            return -1;
        if(node->val==p)
            return 0;
        int l = dfs(node->left, p);
        if(l!=-1)
            return l+1;
        int r = dfs(node->right, p);
        if(r!=-1)
            return r+1;
        return -1;
    }

    TreeNode *lcf(TreeNode *node, int p, int q)
    {
        if(!node)
            return nullptr;
        if(node->val==p || node->val==q)
            return node;
        TreeNode *left = lcf(node->left, p, q);
        TreeNode *right = lcf(node->right, p, q);
        if(left && right)
            return node;
        return left?left:right;
    }

    int findDistance(TreeNode* root, int p, int q) {
        TreeNode *fa = lcf(root, p, q);
        int len1 = dfs(fa, p);
        int len2 = dfs(fa, q);
        return len1+len2;
    }
};
