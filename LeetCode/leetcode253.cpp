class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len<2)   return 1;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
        {
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0; i<len; ++i)
        {
            if(!q.empty() && intervals[i][0] >= q.top())
            {
                q.pop();
            }
            q.push(intervals[i][1]);
        }
        return q.size();
    }
};
