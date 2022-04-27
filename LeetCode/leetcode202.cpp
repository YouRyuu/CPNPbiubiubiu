class Solution {
public:
    int getNext(int n)
    {
        int sum = 0;
        while(n>0)
        {
            int i = n % 10;
            n = n / 10;
            sum += i*i;
        }
        return sum;
    }

    bool isHappy(int n) {
        // unordered_set<int> s;
        // while(n!=1 && s.count(n)==0)
        // {
        //     s.insert(n);
        //     n = getNext(n);
        // }
        // return n==1;

        int slow = n, fast = getNext(n);
        while(fast!=1 && slow!=fast)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast==1;
    }
};
