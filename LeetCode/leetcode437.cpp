// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    int rootSum(TreeNode *node, long long target)
    {
        if(!node)
            return 0;
        long long  ret = 0;
        if(node->val==target)
            ++ret;
        ret += rootSum(node->left, target-node->val);
        ret += rootSum(node->right, target-node->val);
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        long long ret = 0;
        ret = rootSum(root, targetSum);
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        return ret;
    }
};


