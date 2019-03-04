int reverse(int x) {
    int count = 0;
    int result = 0;
    while(x)
    {
        count = x%10;
        x /= 10;
        if (result > INT_MAX/10 || (result == INT_MAX / 10 && count > 7)) return 0;
        if (result < INT_MIN/10 || (result == INT_MIN / 10 && count < -8)) return 0;
        result = result * 10 + count;
    }
    return result;
}