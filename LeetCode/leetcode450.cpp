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
    int succer(TreeNode *node)  //寻找后继节点
    {
        node = node->right;
        while(node->left!=nullptr)
            node = node->left;
        return node->val;
    }

    int preer(TreeNode *node)       //寻找前驱节点
    {
        node = node->left;
        while(node->right!=nullptr)
            node = node->right;
        return node->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
            return nullptr;
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else
        {
            if(root->left==nullptr && root->right==nullptr)
            {
                root=nullptr;
            }
            else if(root->right!=nullptr)
            {
                root->val = succer(root);
                root->right = deleteNode(root->right, root->val);
            }
            else
            {
                root->val = preer(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};
