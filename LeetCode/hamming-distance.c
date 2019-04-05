int hammingDistance(int x, int y) {
    int result;
    result = x^y;
    int count = 0;
    while(result>0)
    {
        if(result&1) 
            count++;
        result=result>>1;
    }
    return count;
}