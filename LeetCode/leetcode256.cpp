class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int red = costs[0][0];
        int blue = costs[0][1];
        int green = costs[0][2];
        for(int i=1; i<costs.size(); ++i)
        {
            int newred = min(blue, green) + costs[i][0];
            int newblue = min(red, green) + costs[i][1];
            int newgreen = min(red, blue) + costs[i][2];
            red = newred, blue = newblue, green = newgreen;
        }
        return min(red, min(blue, green));
    }
};
