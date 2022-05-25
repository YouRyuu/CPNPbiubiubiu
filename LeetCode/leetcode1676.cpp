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
    unordered_set<TreeNode*> s;
    TreeNode *dfs(TreeNode *root, unordered_set<TreeNode*> &s)
    {
        if(!root)
            return nullptr;
        if(s.count(root))
            return root;
        TreeNode *left = dfs(root->left, s);
        TreeNode *right = dfs(root->right, s);
        if(left && right)
            return root;
        return left?left:right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        for(auto &node : nodes)
            s.insert(node);
        return dfs(root, s);
    }
};
