class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        for(int i=0;i<=num;i++)
        {
            result[i] = result[i>>1] + (i&1);
        }
        return result;
    }
};

/**
 * 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
 * 运用动态规划:
 *      给定一个数N,若N是偶数 ,那么他含1的个数跟N/2这个数字含1的个数相等(N = N/2<<1)
 *      同样的,若N是奇数,那么含1的个数就是N/2含1的个数加1(N=N/2<<1 + 1)
 *      则递推公式为:
 *          dp[i] = dp[i/2] + (i&1)     这里i&1用来判断这个数是偶数还是奇数
 * /