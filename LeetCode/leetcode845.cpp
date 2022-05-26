class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int len = arr.size();
        int start = 0, end = -1, mid = -1;
        int ret = 0;
        for(int i=1; i<len; ++i)
        {
            if(arr[i]>arr[i-1])     //后一个值比前一个大
            {
                if(end!=-1)     //山脉消失
                {
                    ret = max(ret, end-start+1);
                    start = end;
                    mid = i;
                    end = -1;
                }
                else        //山脉还在前半段
                    mid = i;
            }
            else if(arr[i] < arr[i-1])
            {
                if(mid==-1)     //
                    start = i;
                else
                    end = i;
            }
            else
            {
                if(mid==-1)
                    start = i;
                else if(mid==i-1)
                {
                    start = mid;
                    mid = -1;
                }
                else
                {
                    ret = max(ret, end-start+1);
                    start = i;
                    end = -1;
                    mid = -1;
                }
            }
        }
        if(end!=-1)
            ret = max(ret, end-start+1);
        return ret;
    }
};
