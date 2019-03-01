#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10] = {999,10,4,3,78,52,5,9,77,30};
    insertion(a);
    for(int i=0; i<10; i++)
        printf("%d,", *(a+i));
    return 0;
}

void insertion(int a[])
{
    for(int i=1; i<10; i++)
    {
        for(int j=i; j>0 && a[j]<a[j-1]; j--)
        {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
        }
    }
}