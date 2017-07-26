#include <stdio.h>
#include "test.h"
#include <time.h>

void main(int argc, char const *argv[])
{
	clock_t begin = clock();
	int Array[]={3,2,4,5,1,9};
	int size = sizeof(Array)/sizeof(int);
	bubble_sort(Array,size,compare);
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n",Array[i] );
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("code time excution %f\n",time_spent );
}
