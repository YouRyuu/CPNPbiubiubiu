class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        int left = 0, right = len - 1;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(numbers[mid] < numbers[right])
                right = mid;
            else if(numbers[mid] > numbers[right])
                left = mid + 1;
            else
                --right;
        }
        return numbers[left];
    }
};
