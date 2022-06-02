class WordDistance {
public:
    unordered_map<string, vector<int>> m;
    WordDistance(vector<string>& wordsDict) 
    {
        for(int i=0; i<wordsDict.size(); ++i)
            m[wordsDict[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        vector<int> w1 = m[word1];
        vector<int> w2 = m[word2];
        int len1 = w1.size(), len2 = w2.size();
        int pos1 = 0, pos2 = 0;
        int ret = INT_MAX;
        while(pos1<len1 && pos2<len2)
        {
            int index1 = w1[pos1], index2 = w2[pos2];
            ret = min(ret, abs(index1-index2));
            if(index1<index2)
                ++pos1;
            else
                ++pos2;
        }
        return ret;
    }
};
