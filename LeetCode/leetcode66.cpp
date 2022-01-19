class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int count = 0;
        int value;
        for(int i=size-1;i>=0;--i)
        {
            if(i==size-1)
                value = digits[i] + 1;
            else
                value = digits[i] + count;
            if(value>=10)
            {
                value = value - 10;
                count = 1;
                digits[i] = value;
            }
            else
            {
                count = 0;
                digits[i] = value;
                break;
            }
        }
        if(count)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;

    }
};
