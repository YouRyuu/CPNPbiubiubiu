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
    unordered_map<int, int> m;
    int maxv;
    int dfs(TreeNode *node)
    {
        if(!node)
            return 0;
        int L = dfs(node->left);
        int R = dfs(node->right);
        int sum = node->val + L + R;
        ++m[sum];
        if(m[sum] > maxv)
            maxv = m[sum];
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxv = 0;
        dfs(root);
        vector<int> ret;
        for(auto item : m)
        {
            if(item.second==maxv)
                ret.push_back(item.first);
        }
        return ret;
    }
};
