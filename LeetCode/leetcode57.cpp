class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        vector<int> temp;
        int size = intervals.size();
        if(size==0)
        {
            ret.push_back(newInterval);
            return ret;
        }
        int i=0;
        int flag = 0;
        while(i<size)
        {
            if(flag)
            {
                ret.push_back(intervals[i]);
                ++i;
                continue;
            }

            if(intervals[i][0]>newInterval[1])
            {
                 ret.push_back(newInterval);
                flag=1;
                continue;
            }

            if(intervals[i][1]<newInterval[0])
            {
                ret.push_back(intervals[i]);
                ++i;
            }
            else
            {
                if(intervals[i][0]<=newInterval[0])
                {
                    temp.push_back(intervals[i][0]);
                }
                else
                {
                    temp.push_back(newInterval[0]);
                }

                if(intervals[i][1]>=newInterval[1])
                {
                    temp.push_back(intervals[i][1]);
                    flag = 1;
                    ++i;
                    ret.push_back(temp);
                }
                else
                {
                    ++i;
                    while(i<size)
                    {
                        if(intervals[i][0]>newInterval[1])
                        {
                            temp.push_back(newInterval[1]);
                            flag = 1;
                            //--i;
                            ret.push_back(temp);
                            break;
                        }
                        else
                        {
                            if(newInterval[1]<=intervals[i][1])
                            {
                                temp.push_back(intervals[i][1]);
                                flag = 1;
                                ret.push_back(temp);
                                ++i;
                                break;
                            }
                            else
                            {
                                ++i;
                            }
                        }
                    }
                    if(i==size && !flag)
                    {
                            temp.push_back(newInterval[1]);
                            ret.push_back(temp);
                            flag = 1;
                    }
                        
                }

            }
        }
        if(!flag)
        {
            ret.push_back(newInterval);
        }
        return ret;
    }
};



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;                    
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};

