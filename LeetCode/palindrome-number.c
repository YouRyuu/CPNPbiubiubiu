bool isPalindrome(int x) {
    if(x<0) return 0;
    int y = x;
    long result = 0;
    int count = 0;
    while(x)
    {
        count = x % 10;
        result = result*10 + count;
        x = x / 10;
    }
    if(y==result) return 1;
    return 0;
}