class Solution {
public:
    string intToRoman(int num) {
        string ret;
    const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
    };
    for(auto item : valueSymbols)
    {
        while(num >= item.first)
        {
            ret += item.second;
            num -= item.first;
        }
        if(num==0)
            break;
    }
    return ret;
}
};
