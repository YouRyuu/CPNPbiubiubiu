
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/**
 * 最大子数组问题,分治算法,递归,ch4,p40
 * @return
 */
//求出跨过中点的最大和
int find_max_cross_array(int *A, int low, int mid, int high) {
    // 对左边求最大和
    int left_sum = -0x7fffffff - 1; //int最小值
    int sum = 0;
    for (int i = mid; i > low; i--) {
        sum = sum + A[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    // 右边
    int right_sum = -0x7fffffff - 1;
    sum = 0;
    for (int i = mid + 1; i < high; i++) {
        sum = sum + A[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum;
}

//求出两边的最大和
int find_max_array(int *A, int low, int high) {
    if (low == high)
        return A[low];
    else {
        int mid;
        mid = (low + high) / 2;
        int left_sum, right_sum, cross_sum;
        left_sum = find_max_array(A, low, mid);
        right_sum = find_max_array(A, mid + 1, high);
        cross_sum = find_max_cross_array(A, low, mid, high);
        if (left_sum >= right_sum && left_sum >= cross_sum)
            return left_sum;
        else if (right_sum >= left_sum && right_sum >= cross_sum)
            return right_sum;
        else
            return cross_sum;
    }
}
