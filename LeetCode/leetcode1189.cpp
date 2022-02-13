class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count;
        string val("balloon");
        for(auto c:text)
        {
            if(val.find(c)!=val.npos)
            {
                ++count[c];
            }
        }
        return min(count['b'], min(count['a'], min(count['l']/2, min(count['o']/2, count['n']))));

    }
};
