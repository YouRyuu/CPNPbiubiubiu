#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Median3(int *a, int left, int right)
{
    int mid = (left + right) / 2;
    if(a[left] > a[right])  swap(&a[left], &a[right]);
    if(a[left] > a[mid]) swap(&a[left], &a[mid]);
    if(a[mid] > a[right]) swap(&a[mid], &a[right]);
    swap(&a[mid], &a[right-1]);
    return a[right - 1];
}

void qsort(int *a, int left, int right)
{
    if(left>=right) return;
    int i,j;
    int point;
    point = Median3(a, left, right);
    i = left, j=right-1;
    for(;;)
    {
        while(a[++i]<point){ if(i>=right) break;}
        while(a[--j]>point){ if(j<=left) break;}
        if(i<j) 
            swap(&a[i], &a[j]);
        else
            break;
    }
    swap(&a[i], &a[right-1]);
    qsort(a, left, i-1);
    qsort(a, i+1, right);
}

void main()
{
    int a[9] = {18,10,40,9,60,3,75,2,7};
    qsort(a, 0, 8);
    for(int i=0;i<9;i++)
        printf("%d,", a[i]);
}