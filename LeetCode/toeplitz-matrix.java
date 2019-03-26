class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
           int i = 0;
    int j = 0;
    int sums = 0;
    for(i=0;i<matrix.length-1;i++)
    {
        for(j=0;j<matrix[0].length-1;j++)
        {
            if(matrix[i][j]!=matrix[i+1][j+1])
                return false;
        }
    }
    return true;
    } 
}

/*
Runtime: 1 ms, faster than 100.00% of Java online submissions for Toeplitz Matrix.
Memory Usage: 44.4 MB, less than 22.91% of Java online submissions for Toeplitz Matrix.
*/