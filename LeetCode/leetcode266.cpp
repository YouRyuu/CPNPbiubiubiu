class Solution {
public:
    bool canPermutePalindrome(string s) {
        int len = s.size();
        unordered_map<char, int> m;
        for(auto c:s)
            ++m[c];
        int odd=0, even=0;
        for(auto item : m)
        {
            if(item.second%2==0)
                ++odd;
            else
                ++even;
        }
        if(len%2==0)
            return even==0;
        else
            return even==1;
        return true;
    }
};
