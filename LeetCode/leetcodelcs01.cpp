class Solution {
public:
    int leastMinutes(int n) {
        int res = 1, now = 1;
        while(now < n)
        {
            now = 2*now;
            ++res;
        }
        return res;
    }
};
