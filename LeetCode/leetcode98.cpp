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
    // bool dfs(TreeNode *root, int left, int right)
    // {
    //     if(root==nullptr)
    //         return true;
    //     if(root->val <= left || root->val >= right)
    //         return false;
    //     return dfs(root->left, left, root->val) && dfs(root->right, root->val, right);
    // }

    // bool isValidBST(TreeNode* root) {
    //    return dfs(root, LONG_MIN, LONG_MAX);
    // }
    long pre = LONG_MIN;
    bool isValidBST(TreeNode *root)
    {
        if(root==nullptr)
            return true;
        if(!isValidBST(root->left))
            return false;
        if(root->val <= pre)
            return false;
        pre = root->val;
        return isValidBST(root->right);
    }
};
