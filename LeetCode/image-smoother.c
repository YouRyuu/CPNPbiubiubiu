/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int max(int a, int b)
{
    return a>b?a:b;
}
int min(int a, int b)
{
    return a>b?b:a;
}

int** imageSmoother(int** M, int MRowSize, int *MColSizes, int** columnSizes, int* returnSize) {
    *returnSize = MRowSize;
    int **result = malloc(MRowSize*(sizeof(int *)));
    *columnSizes = malloc(MRowSize*sizeof(int));
    for(int i=0;i<MRowSize;i++)
    {
        (*columnSizes)[i] = *MColSizes;
        int *row = malloc(*MColSizes*sizeof(int));
        for(int j=0;j<*MColSizes;j++)
        {
            int sum = 0;
            int count = 0;
            for(int x=max(0, i-1);x<=min(MRowSize-1, i+1);x++)      //我死也想不到的解决边界的方法,QvQ
            {
                for(int y=max(0,j-1);y<=min(*MColSizes-1,j+1);y++)
                {
                    sum+=M[x][y];
                    count++;
                }
            }
        row[j] = sum/count;
        }
        result[i] = row;
    }
    return result;
}