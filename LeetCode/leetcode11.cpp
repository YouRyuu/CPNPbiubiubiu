class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxValue = 0;
        int size = height.size();
        int temp = 0;
        int left = 0, right = size-1;
        for(;left!=right;)
        {
            int minValue = height[left]<height[right]?height[left]:height[right];
            temp = minValue*(right-left);
            maxValue = maxValue>temp?maxValue:temp;
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return maxValue;
    }
};
