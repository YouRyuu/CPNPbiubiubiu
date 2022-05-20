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

    void dfs(TreeNode *node, int nowDepth, int val, int depth)
    {
        if(!node)
            return;
        if(nowDepth>=depth)
            return;
        if(nowDepth + 1 == depth)
        {
            TreeNode *L = new TreeNode(val);
            TreeNode *R = new TreeNode(val);
            L->left = node->left;
            node->left = L;
            R->right = node->right;
            node->right = R;
            return ;
        }
        dfs(node->left, nowDepth+1, val, depth);
        dfs(node->right, nowDepth+1, val, depth);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            root = newRoot;
        }
        else
            dfs(root, 1, val, depth);
        return root;
    }
};
