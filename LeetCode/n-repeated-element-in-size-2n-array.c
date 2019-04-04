//有一半的数相等，那么排列中要么所有相同的数都不相邻，要么就必定存在相邻并相等的情形
int repeatedNTimes(int* A, int ASize) {
    int i;
    if(A[1]==A[3]) return A[1];
    for(int i=0;i<ASize-1;i++)
        if(A[i]==A[i+1])
            return A[i];
    return A[0];
}