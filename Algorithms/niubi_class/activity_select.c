#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/**
 * from 算法导论(第三版) ch16:贪心算法,活动选择问题
 * 自顶向下方法
 */

void activate_select(int *s, int *f, int k, int n, int *result, int index)
{
    /**
     * 贪心算法解决活动选择问题, s为开始时间, f为结束时间
     * S[k] = {a[i] in S: S[i]>=f[k]}
     */
    int m = k + 1;
    while(m<=n && s[m]<f[k])    // 找到第一个在Sk结束后开始的活动
    {
        m++;
    }
    if(m<=n){
        result[index] = m;
        index++;
        return activate_select(s, f, m, n, result, index);
    }
    else
        return ;

}

int main(int argc, char *argv[]) {
    int s[] = {0,1,3,0,5,3,5,6,8,8,2,12};
    int f[] = {0,4,5,6,7,9,9,10,11,12,14,16};
    int result[11];
    activate_select(s, f, 0, 11, result, 0);
    for(int i=0;i<11;i++)
        printf("%d,", result[i]);
    return 0;
}