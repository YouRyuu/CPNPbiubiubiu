/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)  return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ret;
        int csize;
        while(!q.empty())
        {
            vector<int> v;
            csize = q.size();
            for(int i=0; i<csize; ++i)
            {
                TreeNode *temp = q.front();
                v.push_back(temp->val);
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ret.push_back(v);            
        }
        return ret;
    }
};
