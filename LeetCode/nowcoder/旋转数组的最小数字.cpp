class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(!rotateArray.size()) return 0;
        int min = 0;
        for(int i=0;i<rotateArray.size();i++)
        {
            if(rotateArray[i]>=min)
            {
                min = rotateArray[i];
            }
            else
            {
                return rotateArray[i];
            }
        }
        return rotateArray[rotateArray.size()-1];
    }
};

//https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking