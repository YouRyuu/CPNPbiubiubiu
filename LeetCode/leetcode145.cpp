class Solution {
public:

    void func(TreeNode*root, vector<int>& ret)
    {
        if(root==nullptr) return;
        func(root->left, ret);
        func(root->right, ret);
        ret.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        func(root, ret);
        return ret;
    }
};
