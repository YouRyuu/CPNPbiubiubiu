#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];
    for(int i=0; i<10; i++)
            scanf("%d", &a[i]);
    selection(a);
    for(int i=0; i<10; i++)
        printf("%d,", *(a+i));
    return 0;
}

void selection(int a[])
{
    for(int i=0; i<10; i++)
    {
        int min = i;
        for(int j=i+1; j<10; j++)
        {
            if(a[min]>a[j])
                    min = j;
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}