class Solution {
public:
    vector<int> ret;
    void order(TreeNode *node)
    {
        if(node==NULL)
            return;
        order(node->left);
        ret.push_back(node->val);
        order(node->right);
    }

    int kthLargest(TreeNode* root, int k) {
        order(root);
        int len = ret.size();
        return ret[len-k];
    }
};
