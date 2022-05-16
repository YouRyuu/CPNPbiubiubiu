class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *curr=root, *next = NULL;
        while(curr)
        {
            if(curr->val > p->val)
            {
                next = curr;
                curr = curr->left;
            }
            else
                curr = curr->right;
        }
        return next;
    }
};
