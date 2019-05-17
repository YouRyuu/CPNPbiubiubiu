//https://leetcode.com/problems/palindromic-substrings
class Solution {
public:
    int countSubstrings(string s) {
        //dp[i][j] = dp[i+1][j-1] && s[i]==s[j]     i和j不相邻
        //dp[i][j] = s[i]==s[j] i和j相邻
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(j-i==1)
                    dp[i][j] = s[i]==s[j];
                else
                    dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
            }
        }
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(dp[i][j]==1) count++;
        }
        return count;
    }
};

//4ms best resv
class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        
        int pal = 0;
        for(int cen = 0; cen < 2 * n; cen++) {
            int left = cen / 2;
            int right = left + cen % 2;
            while(left >= 0 && right < n && s[left] == s[right]) {
                pal++;
                left--;
                right++;
            }
        }
        
        return pal;
    }
};