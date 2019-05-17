//https://leetcode-cn.com/problems/arithmetic-slices
//虽然很慢,但是是我做出来的第一个动态规划题目,23333,真菜
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=i+2;j<n;j++)
            {
                if(j==i+2)
                    dp[i][j] = (A[i+1]-A[i]) == (A[j]-A[j-1]);
                else
                    dp[i][j] = dp[i][j-1] && (A[j]-A[j-1]==A[i+1]-A[i]);
            }
        }
        int count = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dp[i][j]) count++;
        return count;
    }
};


//best recv
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        int dp=0;
        int sum=0;
        for(int i=2;i<n;i++){
            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                dp=dp+1;
                sum+=dp;
            }
            else{
                dp=0;
            }
        }
        return sum;
        
    }
};