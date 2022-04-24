class Solution {
public:
    unordered_map<char, vector<char>> f;
    vector<string> ret;
    string v;
    void bt(string &digits, int index, int len)
    {
        if(v.size()==len)
        {
            ret.push_back(v);
            return;
        }
        for(int i=0; i<f[digits[index]].size(); ++i)
        {
            v.push_back(f[digits[index]][i]);
            bt(digits, index+1, len);
            v.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        f['2'] = {'a', 'b', 'c'};
        f['3'] = {'d', 'e', 'f'};
        f['4'] = {'g', 'h', 'i'};
        f['5'] = {'j', 'k', 'l'};
        f['6'] = {'m', 'n', 'o'};
        f['7'] = {'p', 'q', 'r', 's'};
        f['8'] = {'t', 'u', 'v'};
        f['9'] = {'w', 'x', 'y', 'z'};
        int len = digits.size();
        if(len==0)  return {};
        bt(digits, 0, len);
        return ret;
    }
};
