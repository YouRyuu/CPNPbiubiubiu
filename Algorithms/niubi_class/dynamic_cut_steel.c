#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a)>(b)?(a):(b))

/**
 * from 算法导论(第三版) ch15:动态规划,切割钢条
 * 自底向上
 * @return
 */
int *cut_rod(int p[], int n, int *result) {
    int r[n + 1];       //存放每一长度的最优结果
    int *s = (int *)malloc(sizeof(int)*(n+1));      //存放应该分割的长度
    r[0] = 0;
    s[0] = 0;
    int i, j, q;
    for (i = 0; i < n; i++) {
        q = -1;
        for (j = 0; j <= i; j++) {
            if (q < p[j] + r[i - j]) {  //最优解
                q = p[j] + r[i - j];
                s[i+1] = j+1;
            }
        }
        r[i + 1] = q;
    }
    *result = r[n];
    return s;
}

int main() {
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int *a;
    int result;
    int n;
    printf("请输入钢条长度:");
    scanf("%d", &n);
    a = cut_rod(p, n, &result);
    printf("%d %d", *(a+n), n-*(a+n));
//    for(int i=1;i<8;i++)
//        printf("%d,",*(a+i));
    printf(",,,%d", result);
}
