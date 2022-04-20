class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand;
        int count = 0;
        for(int num: nums)
        {
            if(count==0)
                cand = num;
            if(num==cand)
                ++count;
            else
                --count;
        }
        return cand;
    }
};
