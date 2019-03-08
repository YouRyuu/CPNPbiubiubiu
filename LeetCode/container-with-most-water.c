int maxArea(int* height, int heightSize) {
    int max_ = 0;
    int left = 0;
    int right = heightSize - 1;
    int high;
    while(left<right)
    {
        high = height[left]<height[right]?height[left]:height[right];
        max_ = max_>(high*(right-left))?max_:high*(right-left);
        if(height[left]<height[right])
            left++;
        else
            right--;
    }
    return max_;
}