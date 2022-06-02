class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int len = wordsDict.size();
        int index1 = -1;
        int index2 = -1;
        int ret = INT_MAX;
        for(int i=0; i<len; ++i)
        {
            if(wordsDict[i] == word1)
            {
                if(word1==word2)
                {
                    if(index1!=-1 && index1>index2)
                        index2 = i;
                    else
                    {
                        if(index1<=index2)
                            index1 = i;
                        else
                            index2 = i;
                    }
                }
                else
                    index1 = i;
            }
            else if(wordsDict[i] == word2)
            {
                index2 = i;
            }
            if(index1>=0 && index2>=0)
                ret = min(ret, abs(index1-index2));
        }
        return ret;
    }
};
