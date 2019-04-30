//
// Created by youryuu on 19-4-30.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
矩阵链乘法.算法导论p211
 */

int **matrix_chain_order(int *p, int length) {
    /**
     * p[i]:矩阵A[i]的规模(row*col), length:p的长度
     * 递推公式:
     *         ,->0      if i=j
     * m[i][j]=|
     *         `->min{m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]      if i<j
     *          i<=k<j
     */
    int n = length - 1;
    int m[n + 1][n + 1];       // m[i][j]表示A[i]到A[j]所需乘法次数的最小值
    int **s = (int **) malloc(n * sizeof(int *));       // A[i]到A[j]最优括号化方案的分割点位置K
    s[0] = (int *) malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
        s[i] = (int *) malloc((n + 1) * sizeof(int));
    }
    for (int l = 2; l <= n; l++)   // l代表当前计算链的长度
    {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = 0x7fffffff;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return s;
}

int main() {
    int p[7] = {30, 35, 15, 5, 10, 20, 25};
    int **result;
    result = matrix_chain_order(p, 7);
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 6; j++)
            printf("s[%d][%d]=%d,", i, j, result[i][j]);
    }
    return 0;
}