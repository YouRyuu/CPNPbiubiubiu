/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> cache;
    Node* copyRandomList(Node* head) {
        if(head==NULL)  return NULL;
        if(!cache.count(head))
        {
            Node *newHead = new Node(head->val);
            cache[head] = newHead;
            newHead->next = copyRandomList(head->next);
            newHead->random = copyRandomList(head->random);
        }
        return cache[head];
        // if(head==NULL)  return NULL;
        // unordered_map<Node*, Node*> random;
        // random[head] = head->random;
        // Node *node = head->next;
        // Node *newHead = new Node(head->val);
        // Node *newNode = newHead;
        // while(node!=NULL)
        // {
        //     random[node] = node->random;
        //     newNode->next = new Node(node->val);
        //     newNode = newNode->next;
        //     node = node->next;
        // }
        // newNode = newHead;
        // node = head;
        // while(newNode!=NULL)
        // {
        //     newNode->random = random[node];
        //     newNode = newNode->next;
        //     node = node->next;
        // }
        // return newHead;
    }
};
