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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        queue<TreeNode*> q;
        int sz;
        q.push(root);
        while(!q.empty())
        {
            sz = q.size();
            int maxV = q.front()->val;
            for(int i=0; i<sz; ++i)
            {
                if(q.front()->val > maxV)
                    maxV = q.front()->val;
                TreeNode *v = q.front();
                q.pop();
                if(v->left)
                    q.push(v->left);
                if(v->right)
                    q.push(v->right);
            }
            ret.push_back(maxV);
        }
        return ret;
    }
};
