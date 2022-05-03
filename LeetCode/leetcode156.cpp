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
    TreeNode *head = nullptr;

    void dfs(TreeNode *root, TreeNode *pre)
    {
        if(root==nullptr)
            return;
        dfs(root->left, root);
        if(head==nullptr)
            head = root;        //head等于最左子节点
        if(pre)     //存在父节点（root的父节点为空)
        {
            root->left = pre->right;
            root->right = pre;
            pre->left = nullptr;
            pre->right = nullptr;
        }
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        dfs(root, nullptr);
        return head;
    }
};
