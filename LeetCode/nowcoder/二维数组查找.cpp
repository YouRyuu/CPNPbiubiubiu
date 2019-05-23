class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int col = array[0].size();
        int row = array.size();
        int i=row-1, j=0;
        while(i>=0 && j<col)
        {
            if(array[i][j]<target)
                ++j;
            else if(array[i][j]>target)
                --i;
            else
                return 1;
        }
        return 0;
    }
};
//https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking