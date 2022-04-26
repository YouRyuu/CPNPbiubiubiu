class LRUCache {
public:
    struct LinkList
    {
        LinkList(int k, int v):key(k), value(v), next(nullptr), prev(nullptr)
        {}
        LinkList():key(0), value(0), next(nullptr), prev(nullptr)
        {}
        int key;
        int value;
        LinkList *next;
        LinkList *prev;
    };
    int size;
    int Lsize;
    LinkList *head, *tail;
    unordered_map<int, LinkList*> m;
    LRUCache(int capacity) {
        size = capacity;
        head = new LinkList();
        tail = new LinkList();
        head->next = tail;
        tail->prev = head;
        Lsize = 0;
    }
    
    int get(int key) {
        if(m.count(key)==0)
            return -1;
        else
        {
            LinkList *node = m[key];
            //移动到链表的头部
            node->prev->next = node->next;
            node->next->prev = node->prev;

            head->next->prev = node;
            node->next = head->next;
            node->prev = head;
            head->next = node;

            return node->value;
               
        }
    }
    
    void put(int key, int value) {
        if(m.count(key)!=0)
        {
            //已经存在了，更新，并把该节点移动到链表头部
            LinkList *node = m[key];
            node->value = value;
            
            node->prev->next = node->next;
            node->next->prev = node->prev;

            head->next->prev = node;
            node->next = head->next;
            node->prev = head;
            head->next = node;
        }
        else
        {
            //不存在，就在头部添加，然后判断是否超过size
            LinkList *node = new LinkList(key, value);
            m[key] = node;

            head->next->prev = node;
            node->next = head->next;
            node->prev = head;
            head->next = node;
            ++Lsize;
            if(Lsize > size)
            {
                //删除尾部节点
                LinkList *temp = tail->prev;
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                m.erase(temp->key);
                delete temp;
                --Lsize;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
