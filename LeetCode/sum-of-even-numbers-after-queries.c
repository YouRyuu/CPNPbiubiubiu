int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesRowSize, int queriesColSize, int* returnSize) {
    *returnSize = queriesRowSize;
    int i = 0;
    int *answer = (int *)malloc(sizeof(int)*ASize);
    int sum = 0;
    for(int j=0;j<ASize;j++)
        if(A[j]%2==0)
            sum += A[j];
    while(i<ASize)
    {
        int val = *((int *)(queries+i)+0);
        int index = *((int *)(queries+i)+1);
        if(A[index] % 2 == 0)
            sum = sum - A[index];
        A[index] = A[index] + val;
        if(A[index] % 2 == 0)
            sum = sum + A[index];
        answer[i] = sum;
        i++;
    }
    return answer;
}
/* over heap on leetcode but my computer is ok
*/

/*python:
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        S = sum(x for x in A if x % 2 == 0)
        ans = []

        for x, k in queries:
            if A[k] % 2 == 0: S -= A[k]
            A[k] += x
            if A[k] % 2 == 0: S += A[k]
            ans.append(S)

        return ans
*/