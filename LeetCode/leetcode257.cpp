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
    vector<string> ret;
    void dfs(TreeNode *node, string path)
    {
        if(node==nullptr)
            return;
        if(node->left==nullptr && node->right==nullptr)
        {
            path+=to_string(node->val);
            ret.push_back(path);
            return;
        }
        path+=to_string(node->val);
        path+="->";
        dfs(node->left, path);
        dfs(node->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ret;
    }
};
