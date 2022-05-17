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
    TreeNode *prev, *first, *second;
    void dfs(TreeNode *node)
    {
        if(node==nullptr)
            return;
        dfs(node->left);
        if(node->val < prev->val)
        {
            second = node;
            if(!first)
                first = prev;
        }
        prev = node;
        dfs(node->right);
    }

    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN), first=nullptr, second = nullptr;
        dfs(root);
        if(first && second)
        {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};
