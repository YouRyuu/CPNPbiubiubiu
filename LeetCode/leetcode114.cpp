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
    vector<TreeNode*> vt;
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        TreeNode *temp=nullptr;
        TreeNode *curr = root;
        ff(curr);
        curr = root;
        for(auto &it:vt)
        {
            if(it==curr) continue;
            temp = it;
            curr->right = temp;
            curr->left=nullptr;
            curr = temp;
        }
    }
    void ff(TreeNode *node)
    {
        if(node!=nullptr)
        {
            vt.push_back(node);
            ff(node->left);
            ff(node->right);
        }
    }
};
