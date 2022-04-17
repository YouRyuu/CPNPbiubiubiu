class CQueue {
public:
        stack<int> s1;
        stack<int> s2;
    CQueue() {
        
    }
    
    void appendTail(int value) {
        while(!s2.empty())
        {
            int v = s2.top();
            s2.pop();
            s1.push(v);
        }
        s1.push(value);
    }
    
    int deleteHead() {
        while(!s1.empty())
        {
            int v = s1.top();
            s1.pop();
            s2.push(v);
        }
        if(s2.empty())  return -1;
        int v = s2.top();
        s2.pop();
        return v;
    }
};

