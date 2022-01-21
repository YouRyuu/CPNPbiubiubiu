class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int left = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i + 1 == nums.size() || nums[i] + 1 != nums[i + 1]) {
                ans.push_back(std::to_string(nums[left]) + (left == i ? "" : "->" + std::to_string(nums[i])));
                left = i + 1;
            }
        }
        return ans;

    }
};
