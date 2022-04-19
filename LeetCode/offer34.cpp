class Solution {
public:
    vector<vector<int>> ret;
    void dfs(TreeNode *node, int sum, vector<int> &v, int target)
    {
        if(node==NULL)
            return;
        sum += node->val;
        v.push_back(node->val);
        if(node->left==nullptr && node->right==nullptr && sum==target)
        {
            ret.push_back(v); 
            v.pop_back();
            return;
        }
        dfs(node->left, sum, v, target);
        dfs(node->right, sum, v, target);
        v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> v;
        dfs(root, 0, v, target);
        return ret;
    }
};
