class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        int len = height.size();
        stack<int> stk;
        for(int i=0; i<len; ++i)
        {
            while(!stk.empty() && height[i] > height[stk.top()])
            {
                int v = stk.top();
                stk.pop();
                if(stk.empty())
                    break;
                int area = (i-stk.top()-1) * (min(height[i], height[stk.top()])-height[v]);
                ret += area;
            }
            stk.push(i);
        }
        return ret;
    }
};
