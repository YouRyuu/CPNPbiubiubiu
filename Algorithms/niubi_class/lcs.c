//
// Created by youryuu on 19-4-30.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 最长公共子序列问题
 * 算法导论(第三版) p223
 * LCS最优子结构:
 *      X = <x1,x2,...,xm>
 *      Y = <y1,y2,...,yn>
 *      Z = <z1,z2,...,zk>
 *      z为x和y的最优子结构
 * 定理:
 *      1.若Xm==Yn, 则Zk=Xm=Yn, 且Zk-1是Xm-1和Yn-1的一个LCS
 *      2.若Xm!=Yn, 那么Zk!=Xm意味着Z是Xm-1和Y的一个LCS
 *      3.若Xm!=Yn, 那么Zk!=Yn意味着Z是X和Yn-1的一个LCS
 * 递推公式:
 *      令c[i][j]表示Xi和Yj的LCS长度:
 *               , 0                            if i=0 or j=0
 *      c[i][j] =| c[i-1][j-1]+1                if i,j>0 and Xi=Yi
 *               ` max(c[i][j-1],c[i-1][j]      if i,j>0 and Xi!=Yi
 */

int **lcs_length(char *x, char *y, int xlength, int ylength) {
    int **c = (int **) malloc(sizeof(int *) * (xlength + 1));
    for (int i = 0; i <= xlength; i++) {
        c[i] = (int *) malloc(sizeof(int) * (ylength + 1));
    }
    for (int i = 0; i <= xlength; i++)
        c[i][0] = 0;
    for (int i = 0; i <= ylength; i++)
        c[0][i] = 0;
    for (int i = 1; i <= xlength; i++) {
        for (int j = 1; j <= ylength; j++) {
            if (x[i] == y[j]) c[i][j] = c[i - 1][j - 1] + 1;
            else if (c[i - 1][j] >= c[i][j - 1]) c[i][j] = c[i - 1][j];
            else c[i][j] = c[i][j - 1];
        }
    }
    return c;
}

int main() {
    char x[] = {0, 'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char y[] = {0, 'B', 'D', 'C', 'A', 'B', 'A'};
    int **result;
    result = lcs_length(x, y, 7, 6);
    int i = 7, j = 6;
    while (i > 0 || j > 0) {
        if (result[i][j] == result[i - 1][j]) {
            i--;
        } else if (result[i][j] == result[i][j - 1]) {
            j--;
        } else if (result[i][j] == result[i - 1][j - 1] + 1) {
            printf("<-%c", x[i]);
            i--;
            j--;
        }
    }
}


