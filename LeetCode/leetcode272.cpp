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
    queue<int> q;
    void dfs(TreeNode *node, double target, int k)
    {
        if(!node)
            return;
        dfs(node->left, target, k);
        if(q.size()==k)
        {
            if(abs(q.front()-target) > abs(node->val-target))
            {
                q.pop();
                q.push(node->val);
            }
        }
        else
            q.push(node->val);
        dfs(node->right, target, k);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ret;
        dfs(root, target, k);
        while(!q.empty())
        {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
