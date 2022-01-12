class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<string> zuhe;
        unordered_map<string, int> hash;
        string temp;
        int index=0;
        for(auto str:strs)
        {
            zuhe.clear();
            temp = str;
            sort(temp.begin(), temp.end());
            if(hash.count(temp)==0)     //新的字符串
            {
                zuhe.push_back(str);
                ret.push_back(zuhe);
                hash[temp] = index;
                ++index;
            }
            else        //已经有了这字符串
            {
                int _index = hash[temp];
                ret[_index].push_back(str);
            }
        }
        return ret;
    }
};
