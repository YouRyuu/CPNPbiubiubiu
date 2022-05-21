class Solution {
public:

    int find(vector<pair<int, int>> &index, int target)
    {
        int len = index.size();
        if(index[len-1].first < target)
            return -1;
        int L = 0, R = len-1;
        while(L<R)
        {
            int mid = L + (R-L)/2;
            if(index[mid].first==target)
                return index[mid].second;
            if(index[mid].first<target)
                L = mid+1;
            else
                R = mid;
        }
        return index[R].second;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int>> index;
        int len = intervals.size();
        for(int i=0; i<len; ++i)
            index.push_back({intervals[i][0], i});
        sort(index.begin(), index.end());
        vector<int> ret(len, -1);
        for(int i=0; i<len; ++i)
        {
            int val = find(index, intervals[i][1]);
            ret[i] = val;                
        }
        return ret;
    }
};
