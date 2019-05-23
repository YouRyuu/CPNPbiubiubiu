class Solution {
public:
    int jumpFloor(int number) {
        //dp[i] = dp[i-1]+1 +dp[i-2]+2
        if(number==1) return 1;
        if(number==2) return 2;
        vector<int> dp(number+1, 0);
        dp[2] = 2;
        dp[1] = 1;
        for(int i=3;i<=number;i++)
            dp[i] = dp[i-1]+dp[i-2];
        return dp[number];
    }
};

//https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking