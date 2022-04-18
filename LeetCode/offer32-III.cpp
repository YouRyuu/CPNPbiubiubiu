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
        deque<TreeNode *> q;
        q.push_front(root);
        int index = 1;
        vector<vector<int>> ret;
        int csize;
        while(!q.empty())
        {
            csize = q.size();
            vector<int> v;
            if(index%2!=0)      //从左往右打印
            {
                for(int i=0; i<csize; ++i)
                {
                    TreeNode *temp = q.front();
                    v.push_back(temp->val);
                    q.pop_front();
                    if(temp->left)
                        q.push_back(temp->left);
                    if(temp->right)
                        q.push_back(temp->right);
                }
            }
            else
            {
                for(int i=csize-1; i>=0; --i)
                {
                    TreeNode *temp = q[i];
                    v.push_back(temp->val);
                }
                for(int i=0; i<csize; ++i)
                {
                    TreeNode *temp = q.front();
                    q.pop_front();
                    if(temp->left)
                        q.push_back(temp->left);
                    if(temp->right)
                        q.push_back(temp->right);
                }
            }
            ret.push_back(v);
            ++index;
        }
        return ret;
    }
};
