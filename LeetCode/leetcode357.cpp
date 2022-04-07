class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    int prod = 9; //累计乘积
    int left = 9; //剩余数字个数
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + prod;
        prod *= left;
        left -= 1;
    }
    return dp[n];
}
};
