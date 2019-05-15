/**
 * from 算法导论(第三版) ch16:贪心算法,活动选择问题
 * 动态规划方法
 */
int dy_activity_select(int *s, int *f, int n) {
    int c[n + 2][n + 2];
    for (int i = 0; i < n + 2; i++) {
        p[i] = 0;
        for (int j = 0; j < n + 2; j++)
            c[i][j] = 0;
    }
    int i, j, k;
    for (i = 0; i < n + 1; i++) {
        for (j = i + 1; j < n + 2; j++) {
            for (k = i + 1; k < j; k++) {
                if (s[k] >= f[i] && f[k] <= s[j])//s【i，j】不为空
                {
                    if (c[i][j] <= (c[i][k] + 1 + c[k][j])) {
                        c[i][j] = (c[i][k] + 1 + c[k][j]);
                    }
                }
            }
        }
    }
    return c[0][8];
}