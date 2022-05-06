class LRUCache {
public:
    unordered_map<int, int> m;
    class ListNode
    {
        public:
            ListNode():val(0), next(nullptr), prev(nullptr){}
            ListNode(int v):val(v), next(nullptr), prev(nullptr){}
            int val;
            ListNode *next;
            ListNode *prev;
    };
    ListNode *head, *tail;
    int sz;
    int cap;
    LRUCache(int capacity) {
        sz = 0;
        cap = capacity;
        head = new ListNode;
        tail = new ListNode;
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
    }
    
    int get(int key) {
        if(sz==0 || m.count(key)==0)
            return -1;
        else
            {
                updateNode(key);
                return m[key];
            }
    }
    
    void put(int key, int value) {
        if(m.count(key))
        {
            m[key] = value;
            updateNode(key);
        }
        else
        {
            if(sz==cap)
            {
                int v = returnLastNodeVal();
                m.erase(v);
                deleteLastNode();
                --sz;
            }
            ++sz;
            m[key] = value;
            insertNode(key);            
        }
    }

    int returnLastNodeVal()
    {
        return tail->prev->val;
    }

    void deleteLastNode()
    {
        ListNode *temp = tail->prev;
        temp->prev->next = tail;
        tail->prev = temp->prev;
        delete temp;
    }

    void updateNode(int key)
    {
        if(head->next->val==key)    //已经是第一个节点了
            return;
        ListNode *node = head->next;
        while(node!=tail)
        {
            if(node->val==key)
                break;
            node = node->next;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void insertNode(int key)
    {
        ListNode *node = new ListNode(key);
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
