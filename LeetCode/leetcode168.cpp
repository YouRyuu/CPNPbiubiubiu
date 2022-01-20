class Solution {
public:
    string convertToTitle(int columnNumber) {
        string dict="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ret;
        while (columnNumber > 0) {
            --columnNumber;
            ret += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
        

    }
};
