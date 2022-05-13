class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> visited(26,0);
        vector<int> nums(26,0);
        for(auto c:s)
            ++nums[c-'a'];
        string ret;
        for(auto ch : s)
        {
            if(!visited[ch-'a'])        //没有被记录
            {
                while(!ret.empty() && ret.back() > ch)      //
                {
                    if(nums[ret.back()-'a'] > 0)
                    {
                        visited[ret.back()-'a'] = 0;
                        ret.pop_back();
                    }
                    else
                        break;
                }
                visited[ch-'a'] = 1;
                ret.push_back(ch);
            }
            --nums[ch-'a'];
        }
        return ret;
    }
};
