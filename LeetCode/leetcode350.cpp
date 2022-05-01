class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for(int num : nums1)
        {
            ++m1[num];
        }
        for(int num : nums2)
        {
            ++m2[num];
        }
        vector<int> ret;
        for(auto it=m1.begin(); it!=m1.end(); ++it)
        {
            if(m2.count(it->first))
            {
                int count = min(it->second, m2[it->first]);
                for(int i=0; i<count; ++i)
                    ret.push_back(it->first);                    
            }
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i=0, j=0;
        while(i<len1 && j<len2)
        {
            if(nums1[i] < nums2[j])
                ++i;
            else if(nums1[i] > nums2[j])
                ++j;
            else
            {
                ret.push_back(nums1[i]);
                ++i;++j;
            }
        }
        return ret;
    }
};
