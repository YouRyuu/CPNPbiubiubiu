#include <stdio.h>

int rank(int *a, int key, int N)
{
    int left = 0;
    int right = N-1;
    while(left<=right)
    {
        int mid = (left + right)/2;
        if(a[mid]<key)
            left = mid + 1;
        else if(a[mid]>key)
            right = mid - 1;
        else
        {
            return mid;
        }
    }
    return left;
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int result = rank(a, 2, 10);
    printf("%d",result);
}