int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
       int left = 0;
    int right = numbersSize-1;
    while(left<right)
    {
        if(numbers[left] + numbers[right] == target)
        {
            numbers[0] = left+1;
            numbers[1] = right+1;
            *returnSize = 2;
            break;
        }
        else if(numbers[left]+numbers[right] < target)
            left++;
        else
            right--;
    }
    return numbers;
}