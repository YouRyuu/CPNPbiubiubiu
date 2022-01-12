class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        int size = intervals.size();
        for(int i=0;i<size;++i)
        {
            if(ret.size()==0 || ret.back()[1]<intervals[i][0]) 
                ret.push_back({intervals[i][0], intervals[i][1]});
            else
            {
                ret.back()[1] = ret.back()[1] >= intervals[i][1] ? ret.back()[1]:intervals[i][1];
            }
        }
        return ret;
    }

};
