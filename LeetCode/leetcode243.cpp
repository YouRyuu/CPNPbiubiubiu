class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int length = wordsDict.size();
        int ans = length;
        int index1 = -1, index2 = -1;
        for (int i = 0; i < length; i++) {
            if (wordsDict[i] == word1) {
                index1 = i;
            } else if (wordsDict[i] == word2) {
                index2 = i;
            }
            if (index1 >= 0 && index2 >= 0) {
                ans = min(ans, abs(index1 - index2));
            }
        }
        return ans;
    }
};

