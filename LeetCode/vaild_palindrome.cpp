class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        int len = sgood.size();
        int left = 0, right = len-1;
        while(left<right)
        
        {

        if(sgood[left]!=sgood[right])
            return false;
        left++;
        right--;
        }
        return true;
    }
};
