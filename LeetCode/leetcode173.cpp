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
class BSTIterator {
public:

    stack<TreeNode*> stk;
    TreeNode *p;

    BSTIterator(TreeNode* root) {
        p = root;
    }
    
    int next() {
        while(p)
        {
            stk.push(p);
            p = p->left;
        }
        p = stk.top();
        stk.pop();
        int ret = p->val;
        p = p->right;
        return ret;
    }
    
    bool hasNext() {
        return p!=nullptr || !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
