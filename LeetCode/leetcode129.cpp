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
    int sum = 0;
    int curr = 0;

    void dfs(TreeNode *root)
    {
        if(root==nullptr)
            return;
        curr = curr * 10 + root->val;
        if(root->left==nullptr && root->right==nullptr)
            sum += curr;
        dfs(root->left);
        dfs(root->right);
        curr = (curr-root->val)/10;
    }

    int sumNumbers(TreeNode* root) {
        dfs(root);
        return sum;
    }
};
