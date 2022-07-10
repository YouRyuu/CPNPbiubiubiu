class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
}
;
class Solution {
public:
    pair<int, int> exp(string &s, int L, int R)
    {
        while(L>=0 && R<s.size() && s[L]==s[R])
        {
            --L;
            ++R;
        }
        return {L+1, R-1};
    }

    string longestPalindrome(string s) {
        int len = s.size();
        int start = 0, end = 0;
        for(int i=0; i<len; ++i)
        {
            pair<int, int> exp1 = exp(s, i, i);
            pair<int, int> exp2 = exp(s, i, i+1);
            if((exp1.second-exp1.first) > (end - start))
            {
                end = exp1.second;
                start = exp1.first;
            }
            if((exp2.second - exp2.first) > (end - start))
            {
                end = exp2.second;
                start = exp2.first;
            }
        }
        return s.substr(start, end-start+1);
    }
};
