class MyCircularQueue {
public:

    struct ListNode{
        int val;
        ListNode *next;
        ListNode *prev;
    };
    struct ListNode *head, *tail;
    int size;
    int maxSize;

    MyCircularQueue(int k) :maxSize(k), size(0){
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
    
    bool enQueue(int value) {
        if(size>=maxSize)
            return false;
        else
        {
            tail->val = value;
            tail = tail->next;
            ++size;
            return true;
        }
    }
    
    bool deQueue() {
        if(size==0)
            return false;
        else
        {
            head = head->next;
            --size;
            return true;
        }
    }
    
    int Front() {
        if(size==0)
            return -1;
        return head->val;
    }
    
    int Rear() {
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
