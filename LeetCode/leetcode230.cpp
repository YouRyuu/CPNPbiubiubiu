class Solution {
public:
    vector<int> v;
    void dfs(TreeNode *node)
    {
        if(node==nullptr)
            return;
        dfs(node->left);
        v.push_back(node->val);
        dfs(node->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return v[k-1];
    }
};
