class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> m;
        for(string s : strings)
        {
            string key(s);
            for(auto &c : key)
            {
                c = (c-s[0]+26)%26+'a';
            }
            m[key].push_back(s);
        }
        for(auto item : m)
            ret.push_back(item.second);
        return ret;
    }
};
