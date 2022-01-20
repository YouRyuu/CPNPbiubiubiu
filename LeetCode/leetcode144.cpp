class Solution {
public:

    void func(TreeNode* root, vector<int>& ret)
    {
        if(root==nullptr) return;
        ret.push_back(root->val);
        func(root->left, ret);
        func(root->right, ret);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        func(root, ret);
        return ret;
    }
};
