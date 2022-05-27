/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node *head=NULL, *curr=NULL;
    void dfs(Node* node)
    {
        if(!node)
            return;
        dfs(node->left);
        if(curr)
        {
            curr->right = node;
            node->left = curr;
            curr = node;
        }
        else
            head = node;
        curr = node;        
        dfs(node->right);
    }

    Node* treeToDoublyList(Node* root) {
        if(!root)   return NULL;
        dfs(root);
        head->left = curr;
        curr->right = head;
        return head;
    }
};
