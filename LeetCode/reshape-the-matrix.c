class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        if r*c != len(nums)*len(nums[0]):
            return nums
        res = []
        ans = []
        row = len(nums)
        col = len(nums[0])
        for i in range(row):
            for j in range(col):
                if len(ans)==c:
                    res.append(ans)
                    ans = []
                ans.append(nums[i][j])
        res.append(ans)
        return res
        
//c
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) 
{
    int i, j, count = 0, row = 0, col = 0;
    int **renums = (int**)malloc(sizeof(int *) * r);
    if(numsRowSize * numsColSize < r * c) 
    {
        r = numsRowSize;
        c = numsColSize;
    }

    for(i = 0; i < r; i++)
    {
        renums[i] = (int *)malloc(sizeof(int) * c);
        for(j = 0; j < c; j++)
        {
            renums[i][j] = nums[row][col++];
            if(col == numsColSize) 
            {
                col = 0;
                row += 1;
            }
        }
    }
 
    columnSizes[0] = (int *)malloc(sizeof(int) * r);
    for(i = 0; i < r; i++)
    {
         columnSizes[0][i] = c;
    }  
    *returnSize = r;
    return renums;
}