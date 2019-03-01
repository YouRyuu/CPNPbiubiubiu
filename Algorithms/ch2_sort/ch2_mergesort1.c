#include <stdio.h>

void mergeSort1(int *a, int N)
{
	int lo = 0;
	int hi = N-1;
	int i = lo;
	int mid = (N-1)/2;
	int j = mid + 1;
	int aux[N];
	for(int k=lo;k<N;k++)
		aux[k] = a[k];
	for(int k=lo; k<hi; k++)
	{
		if(i>mid) a[k]=aux[j++];
		else if(j>=hi) a[k]=aux[i++];
		else if(aux[j]<aux[i]) a[k]=aux[j++];
		else a[k]=aux[i++];
	}
}

void main()
{
	int a[10] = {7,2,5,4,6,10,15,12,11,10};

	for(int i=0;i<10;i++)
		printf("%d,",a[i]);
	printf("after sort:\n");
	mergeSort1(a,10);
		for(int i=0;i<10;i++)
		printf("%d,",a[i]);
}
