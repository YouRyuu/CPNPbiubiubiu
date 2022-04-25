/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            while(sz)
            {
                Node *node = q.front();
                q.pop();
                if(sz==1)
                    node->next = NULL;
                else
                    node->next = q.front();
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                --sz;
            }
        }
        return root;
    }
};
//O(1)方法
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        Node *leftNode = root;
        while(leftNode->left!=NULL)
        {
            Node *head = leftNode;
            while(head!=NULL)
            {
                head->left->next = head->right;
                if(head->next!=NULL)
                    head->right->next = head->next->left;
                head=head->next;
            }
            leftNode = leftNode->left;
        }
        return root;
    }
};
