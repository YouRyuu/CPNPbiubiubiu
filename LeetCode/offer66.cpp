class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if(len==0)  return {};
        vector<int> L(len, 0);
        vector<int> R(len, 0);
        vector<int> A(len, 0);
        L[0] = 1;
        R[len-1] = 1;
        for(int i=1; i<len; ++i)
        {
            L[i] = L[i-1] * a[i-1];
        }
        for(int i=len-2; i>=0; --i)
        {
            R[i] = R[i+1] * a[i+1];
        }
        for(int i=0; i<len; ++i)
        {
            A[i] = L[i] * R[i];
        }
        return A;
    }
};
