class Solution {
public:
    bool dfs(TreeNode *A, TreeNode *B)
    {
        if(B==NULL)  return true;
        if(A==NULL)  return false;
        if(A->val==B->val)
        {
            return dfs(A->left, B->left) && dfs(A->right, B->right);
        }
        else
        {
            return false;
        }
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL || B==NULL)  return false;
        if(A->val==B->val && (dfs(A->left, B->left) && dfs(A->right, B->right)))  return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
