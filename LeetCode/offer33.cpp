class Solution {
public:
    bool dfs(vector<int> &postorder, int i, int j)
    {
        if(i>=j)    return true;
        int p=i;
        while(postorder[p]<postorder[j])
            ++p;
        int m=p;
        while(postorder[p]>postorder[j])
            ++p;
        return p==j && dfs(postorder, i, m-1) && dfs(postorder, m, j-1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, postorder.size()-1);
    }
};
