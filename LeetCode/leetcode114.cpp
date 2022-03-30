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
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        while(curr!=nullptr)
        {
            if(curr->left!=nullptr)
            {
                TreeNode *next = curr->left;
                TreeNode *pre = next;
                while(pre->right!=nullptr)
                    pre = pre->right;
                pre->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }
};
