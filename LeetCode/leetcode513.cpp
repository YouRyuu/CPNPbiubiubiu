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
    int ret;
    int maxD;
    void dfs(TreeNode *node, int depth)
    {
        if(!node)
            return;
        if(!node->left && !node->right)
        {
            if(depth > maxD)
            {
                maxD = depth;
                ret = node->val;
            }
        }
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        maxD = -1;
        dfs(root, 0);
        return ret;
        // queue<TreeNode*> q;
        // int sz;
        // q.push(root);
        // int ret;
        // while(!q.empty())
        // {
        //     sz = q.size();
        //     int size = sz;
        //     while(sz)
        //     {
        //         if(sz==size)
        //             ret = q.front()->val;
        //         TreeNode *v = q.front();
        //         q.pop();
        //         if(v->left)
        //             q.push(v->left);
        //         if(v->right)
        //             q.push(v->right);
        //         --sz;
        //     }
        // }
        // return ret;
    }
};
