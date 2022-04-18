class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(root==NULL)  return {};
        queue<TreeNode *> q;
        vector<int> rt;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *temp = q.front();
            rt.push_back(temp->val);
            q.pop();
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
        return rt;        
    }
};
