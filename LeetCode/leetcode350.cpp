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
