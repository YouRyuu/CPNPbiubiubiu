int* sortedSquares(int* A, int ASize, int* returnSize) {
        int *B = (int *)malloc(sizeof(int)*ASize);
    for(int i=0;i<ASize;i++)
    {
        B[i] = A[i] * A[i];
    }
    for(int i=0;i<ASize;i++)
    {
        for(int j=i+1;j<ASize;j++)
        {
            if(B[i]>B[j])
            {
                int temp = B[j];
                B[j] = B[i];
                B[i] = temp;
            }
        }
    }
    *returnSize = ASize;
    return B;
}