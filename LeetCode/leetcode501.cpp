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
    int count;
    int curr;
    int maxv;
    vector<int> ret;

    void update(int val)
    {
        if(val==curr)
            ++count;
        else
        {
            count = 1;
            curr = val;
        }
        if(count==maxv)
            ret.push_back(val);
        if(count > maxv)
        {
            maxv = count;
            ret.clear();
            ret.push_back(val);
        }
    }

    void dfs(TreeNode *node)
    {
        if(!node)
            return ;
        dfs(node->left);
        update(node->val);
        dfs(node->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ret;
    }
};
