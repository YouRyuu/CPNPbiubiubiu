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
    int dfs(TreeNode *node)
    {
        if(node==nullptr)
            return 0;
        int L = dfs(node->left);
        int R = dfs(node->right);
        if(L==-1 || R==-1 || abs(L-R)>1)
        {
            return -1;
        }
        else
            return max(L, R)+1;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root)>=0;
    }
};
