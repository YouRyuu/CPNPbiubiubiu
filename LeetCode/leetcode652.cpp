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
    unordered_map<string, int> m;
    vector<TreeNode*> ret;
    string dfs(TreeNode *node)
    {
        if(!node)
            return "#";
        string val = to_string(node->val) + "," + dfs(node->left) + "," + dfs(node->right);
        if(m.find(val)!=m.end())
        {
            if(m[val]==1)
                ret.push_back(node);
        }
        ++m[val];
        return val;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ret;
    }
};
