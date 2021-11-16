class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        int len = nums.size();
        if(len<3)
            return res;
        for(int i=0;i<len;i++)
        {
            if(nums[i]>0)
                return res;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int l=i+1;
            int r=len-1;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    
                    res.push_back({nums[i],nums[l],nums[r]});
                    
                    while(l<r && nums[l]==nums[l+1])
                        l+=1;
                    while(l<r && nums[r]==nums[r-1])
                        r-=1;
                    l+=1;
                    r-=1;
                }
                else if(nums[i]+nums[l]+nums[r]>0)
                    r-=1;
                else
                    l+=1;
            }
        }
        return res;
    }
};
