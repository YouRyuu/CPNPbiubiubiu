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
    unordered_map<int, int> index;

    TreeNode *dfs(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int poststart, int postend)
    {
        if(poststart > postend)
            return nullptr;
        int postroot = postorder[postend];
        int inroot = index[postroot];
        int nums = inroot-instart;
        TreeNode *root = new TreeNode(postroot);
        root->left = dfs(inorder, postorder, instart, inend-1, poststart, poststart+nums-1);
        root->right = dfs(inorder, postorder, inroot+1, inend, poststart+nums, postend-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); ++i)
            index[inorder[i]] = i;
        return dfs(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
