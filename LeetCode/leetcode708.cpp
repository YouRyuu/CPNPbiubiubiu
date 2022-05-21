/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head)
        {
            head = new Node(insertVal);
            head->next=head;
            return head;
        }
        if(head->next==head)
        {
            Node *v=new Node(insertVal);
            v->next=head;
            head->next=v;
            return head;
        }
        Node *node = head;
        Node *maxNode = head;
        while(node)
        {
            if(node->val>maxNode->val)
                maxNode=node;
            if(node->val<=insertVal && node->next->val >= insertVal)
            {
                Node *v = new Node(insertVal);
                v->next = node->next;
                node->next = v;
                break;
            }
            else
                node=node->next;
            if(node==maxNode)       //找了一圈都没找到
            {
                while(node->val==node->next->val && node->next!=maxNode)
                    node=node->next;
                Node *v = new Node(insertVal);
                v->next=node->next;
                node->next = v;
                break;
            }
        }
        return head;
    }
};
