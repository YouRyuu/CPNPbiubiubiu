class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int temp;
        if(!stack2.empty())
        {
            temp = stack2.top();
            stack2.pop();
        }
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            temp = stack2.top();
            stack2.pop();
        }

        return temp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

//https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking