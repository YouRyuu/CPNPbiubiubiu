class BrowserHistory {
public:
    struct ListNode{
        ListNode(string u):url(u), next(nullptr), prev(nullptr)
        { }
        string url;
        ListNode *next;
        ListNode *prev;
    };
    ListNode *head, *curr;
    BrowserHistory(string homepage) {
        head = new ListNode(homepage);
        curr = head;
    }
    
    void visit(string url) {
        ListNode *node = new ListNode(url);
        curr->next = node;
        node->prev = curr;
        curr = node;
    }
    
    string back(int steps) {
        while(steps)
        {
            if(curr==head)
                return curr->url;
            curr=curr->prev;
            --steps;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps)
        {
            if(!curr->next)
                return curr->url;
            curr=curr->next;
            --steps;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
