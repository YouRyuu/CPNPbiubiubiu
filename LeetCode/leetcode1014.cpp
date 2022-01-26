class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int size = values.size();
        int is=0, ie=1, adds, adde;//is:当前最大观光值时的起始点， ie：终点
        int maxScore = values[is] + values[ie] + is - ie;
        for(int i=2;i<size;++i)
        {
            adds = values[i] + values[is] + is - i; //当前索引和is的观光值
            adde = values[i] + values[ie] + ie - i;//当前索引和ie的观光值
            if(adds > adde) //取最大的，并更新新的is ie
            {
                ie = i;
                maxScore = max(maxScore, adds);
            }
            else
            {
                is = ie;
                ie = i;
                maxScore = max(maxScore, adde);
            }
        }
        return maxScore;

    }
};
