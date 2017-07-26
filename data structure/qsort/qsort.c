#include <stdio.h>
#include "test.h"
void main(int argc, char const *argv[])
{
	int Array[]={3,2,4,5,1,9};
	int size = sizeof(Array)/sizeof(int);
	bubble_sort(Array,size,compare);
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n",Array[i] );
	}
}
