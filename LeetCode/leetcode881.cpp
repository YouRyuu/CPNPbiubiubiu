class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ret = 0;
        sort(people.begin(), people.end());
        int len = people.size();
        int L = 0, R = len-1;
        while(L<=R)
        {
            ++ret;
            if(L==R)
                break;
            else
            {
                if(people[L] + people[R] <=limit)
                {
                    ++L;
                    --R;
                }
                else
                {
                    --R;
                }
            }
        }
        return ret;
    }
};
