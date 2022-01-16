class Solution {
public:
    bool isPalindrome(int x) {
        string temp = to_string(x);
        int len = temp.size();
        int l=0, r=len-1;
        while(l!=r && (l<(len-1)) && (r>0))
        {
            if(temp[l]==temp[r])
            {
                ++l;--r;
            }
            else
            {
                return false;
            }
        }
        return true;


    }
};
