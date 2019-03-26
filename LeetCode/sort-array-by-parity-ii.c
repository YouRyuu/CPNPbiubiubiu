/*
Runtime: 60 ms, faster than 62.27% of C online submissions for Sort Array By Parity II.
Memory Usage: 13.9 MB, less than 100.00% of C online submissions for Sort Array By Parity II.
*/
int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    *returnSize = ASize;
    int index = 0;
    int next = index + 1;
    while(index < ASize - 1)
    {
        if((index%2)==(A[index]%2))
        {
            index++;
            next++;
        }
        else
        {
            while(next<ASize)
            {
                if(A[next]%2==A[index]%2)
                {
                    next+=2;
                }
                else
                {
                    int temp = A[index];
                    A[index] = A[next];
                    A[next] = temp;
                    index+=2;
                    next = index + 1;
                    break;
                }
            }
        }
    }
    return A;
}