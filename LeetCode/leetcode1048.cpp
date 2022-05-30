class Solution {
public:

    bool isSubStr(string &word1, string &word2)
    {
        //word1是word2的子序列且len2-len1=1
        int len1 = word1.size();
        int len2 = word2.size();
        if(len2-len1!=1)
            return false;
        int i=0, j=0;
        while(i<len1 && j<len2)
        {
            if(word1[i]==word2[j])
            {
                ++i;
            }
            ++j;
        }
        return i==len1;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &word1, string &word2){
            return word1.size() < word2.size();
        });
        int len = words.size();
        vector<int> dp(len, 1);
        int ret = 0;
        for(int i=0; i<len; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                if(isSubStr(words[j], words[i]))
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ret = max(dp[i], ret);
        }
        return ret;
    }
};
