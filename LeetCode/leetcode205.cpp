class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int count = 0;
        unordered_map<char, int> hash;
        string s1, t1;
        for(auto &c:s)
        {
            if(hash.count(c)==0)
            {
                hash[c] = ++count;
            }
            else
            {
                s1+=hash[c];
            }
        }
        hash.clear();
        count = 0;
        for(auto &c:t)
        {
            if(hash.count(c)==0)
            {
                hash[c] = ++count;
            }
            else
            {
                t1+=hash[c];
            }
        }
        return s1==t1;
    }
};
