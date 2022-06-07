class Solution {
public:
    vector<string> ret;
    unordered_map<char, int> m;

    void dfs(string v, int len)
    {
        if(v.size()==len)
        {
            ret.push_back(v);
            return;
        }
        for(auto &item:m)
        {
            if(item.second>0)
            {
                item.second -= 2;
                dfs(item.first+v+item.first, len);
                item.second += 2;
            }
        }        
    }

    vector<string> generatePalindromes(string s) {
        int n = s.size();
        for(auto c:s)
            ++m[c];
        int odd = 0;
        char oddchar;
        for(auto item : m)
        {
            if(item.second%2!=0)
            {
                if(odd==1)
                    return {};
                else
                {
                    odd=1;
                    oddchar = item.first;
                }
            }
        }
        string v="";
        if(odd)
        {
            v+=oddchar;
            --m[oddchar];
        }
        dfs(v, n);
        return ret;
    }
};
