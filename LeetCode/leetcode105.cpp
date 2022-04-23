class Solution {
public:
    unordered_map<int, int> index;

    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        if(preStart > preEnd)
            return NULL;
        int preRoot = preStart;
        int inRoot = index[preorder[preRoot]];
        int nodeNums = inRoot - inStart;
        TreeNode *root = new TreeNode(preorder[preRoot]);
        root->left = dfs(preorder, inorder, preRoot+1, preRoot+nodeNums, inStart, inRoot-1);
        root->right = dfs(preorder, inorder, preRoot+nodeNums+1, preEnd, inRoot+1, inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        for(int i=0; i<len; ++i)
            index[inorder[i]] = i;
        return dfs(preorder, inorder, 0, len-1, 0, len-1);
    }
};
