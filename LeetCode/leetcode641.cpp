class MyCircularDeque {
public:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode *prev;
    };
    struct ListNode *head, *tail;
    int size;
    int maxSize;

    MyCircularDeque(int k) :maxSize(k), size(0){
        head = new ListNode;
        tail = head;
        ListNode *v = head;
        for(int i=0; i<k-1; ++i)
        {
            tail = new ListNode;
            v->next = tail;
            tail->prev = v;
            v = v->next;            
        }
        tail->next = head;
        head->prev = tail;
        tail = head;
    }
    
    bool insertFront(int value) {
        if(size>=maxSize)
            return false;
        ++size;
        head = head->prev;
        head->val = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(size>=maxSize)
            return false;
        ++size;
        tail->val = value;
        tail = tail->next;
        return true;
    }
    
    bool deleteFront() {
        if(size==0)
            return false;
        head = head->next;
        --size;
        return true;
    }
    
    bool deleteLast() {
        if(size==0)
            return false;
        tail = tail->prev;
        --size;
        return true;
    }
    
    int getFront() {
        if(size==0)
            return -1;
        return head->val;
    }
    
    int getRear() {
        if(size==0)
            return -1;
        return tail->prev->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
