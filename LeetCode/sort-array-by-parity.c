int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    int index = 0;
    int count = 0;
    while(index < ASize)
    {
        if(A[index]%2==0)
        {
            // A[index] = A[index] + A[count];
            // A[count] = A[index] - A[count];
            // A[index] = A[index] - A[count];
            int temp = A[index];
            A[index] = A[count];
            A[count] = temp;
            count++;
            index++;
        }
        else
            index++;
    }
    *returnSize = ASize;
    return A;
}