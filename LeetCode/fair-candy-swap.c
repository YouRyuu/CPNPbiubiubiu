int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize) {
        int *res = (int *)malloc(sizeof(int)*2);
    *returnSize = 2;
    int Asum=0,Bsum=0;
    for(int i=0;i<ASize;i++)
        Asum+=A[i];
    for(int i=0;i<BSize;i++)
        Bsum+=B[i];
    int dis = Asum-Bsum;
    if(dis==0)
    {
        res[0] = 0;
        res[1] = 0;
    }
    else
    {
        for(int a=0;a<ASize;a++)
            for(int b=0;b<BSize;b++)
            {
                if(A[a]-B[b]==dis/2)
                {
                   res[0] = A[a];
                    res[1] = B[b];
                    break;
                }
            }
    }
    return res;
}


//python
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        Sa, Sb = sum(A), sum(B)
        setB = set(B)
        for x in A:
            if x + (Sb - Sa) / 2 in setB:
                return [x, x + (Sb - Sa) / 2]