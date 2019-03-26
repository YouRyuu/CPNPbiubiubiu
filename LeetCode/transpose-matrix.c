int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    int i, j;
    int** ret = (int**)malloc(sizeof(int*) * (*AColSizes));
    columnSizes[0] = (int*)malloc(sizeof(int) * (*AColSizes));
    *returnSize = *AColSizes;
    for(i = 0; i < *AColSizes; i++) columnSizes[0][i] = ARowSize;
    for(i = 0; i < *AColSizes; i++) ret[i] = (int*)malloc(sizeof(int) * ARowSize);
    for(i = 0; i < ARowSize; i++)
    {
        for(j = 0; j < *AColSizes; j++)
        {
            ret[j][i] = A[i][j];
        }
    }
    return ret;
}

/*
class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        row = len(A)
        col = len(A[0])
        ans = [[None] * row for _ in range(col)]
        for r in range(row):
            for c in range(col):
                ans[c][r] = A[r][c]
        return ans
        # or return list(zip(*A))
        */