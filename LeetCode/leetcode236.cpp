class Solution {
public:
    TreeNode *ret;
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root==NULL) 
            return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);  
        if(lson && rson || ((root->val==p->val || root->val==q->val) && (lson || rson)))
            ret = root;
        return lson || rson || root->val==p->val || root->val==q->val;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ret;
    }
};
