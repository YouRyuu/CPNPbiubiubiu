#include <stdio.h>

/*
 a:array
 i:index of one elem
 N:length of item's number
 */

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swim(int *a, int i, int N)
{
    while(i > 1 && a[i/2]>a[i])
    {
        swap(&a[i/2], &a[i]);
        i = i/2;
    }
}

void sink(int *a, int i, int N)
{
    while(2*i <= N)
    {
        int j = 2*i;
        if(j<N && a[j]<a[j+1])
        j++;
        if(a[i]>a[j]) break;
        swap(&a[i], &a[j]);
        i = j;
    }
}

void headsort(int *a, int N)
{
    for(int i=N/2;i>=1;i--)
    {
        sink(a,i,N);
    }
    while(N>1)
    {
        swap(&a[1],&a[N]);
        N--;
        sink(a,1,N);
    }
}

void main()
{
    int a[10] = {-1,4,7,1,99,23,0,34,67,5};
    headsort(a,9);
    for(int i=1;i<=9;i++)
        printf("%d,", a[i]);
}
