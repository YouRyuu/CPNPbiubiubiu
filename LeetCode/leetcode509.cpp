class Solution {
public:
    int count = 0;
    int fib(int n) {
        if(n<2) return n;
        count = fib(n-1) + fib(n-2);
        return count;

    }
};
