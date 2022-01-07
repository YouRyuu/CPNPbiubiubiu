class MinStack {
    stack<long > st;
    int minvalue;
public:
    MinStack() {
        minvalue=-1;
    }
    
    void push(int val) {
        if(st.size()==0)        //没有元素的时候，第一个元素就是最小值
        {
            minvalue = val;
            st.push(0);
        }
        else
        {
            long diff=(long)val-(long)minvalue;
            if(diff<0)
            {
                minvalue=val;
                
            }
            st.push(diff);
        }
    }
    
    void pop() {
        long diff = st.top();
        if(diff<0)
        {
            minvalue = minvalue-diff;
        }
        st.pop();
    }
    
    int top() {
        long  diff = st.top();
        if(diff>0) return minvalue+st.top();
        else return minvalue;
    }
    
    int getMin() {
        return minvalue;
    }
};

