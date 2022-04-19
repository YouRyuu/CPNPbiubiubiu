class Solution {
public:
    vector<string> rt;
    vector<int> visited;
    void bt(string &s, int i, int n, string &temp)
    {
        if(i==n)
        {
            rt.push_back(temp);
            return;
        }
        for(int j=0; j<n; ++j)
        {
            if(visited[j] || (j>0 && !visited[j-1] && s[j-1]==s[j]))
            {
                continue;
            }
            visited[j] = true;
            temp.push_back(s[j]);
            bt(s, i+1, n, temp);
            temp.pop_back();
            visited[j] = false;
        }
    }

    vector<string> permutation(string s) {
        int len = s.size();
        visited.resize(len);
        sort(s.begin(), s.end());
        string temp;
        bt(s, 0, len, temp);
        return rt;
    }
};
