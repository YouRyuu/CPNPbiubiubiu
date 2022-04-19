class Solution {
public:
    Node *pre, *head;
    void dfs(Node *cur)
    {
        if(cur==NULL)
            return;
        dfs(cur->left);
        if(pre!=NULL)
            pre->right = cur;
        else
            head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(root==NULL)  return NULL;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};
