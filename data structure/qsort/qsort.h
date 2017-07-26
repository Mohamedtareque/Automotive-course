int compare(const void *a , const void *b)
{
	int A = *((int*)a);	
	int B = *((int*)b);	
	return (A > B ? 1 : -1);
}

void bubble_sort(int *Array ,int size, int(*pf)(const void*,const void*) )
{
	int i ,j , temp ; 
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if(pf(&Array[j],&Array[j+1])>0)
			{
				temp = Array[j];
				Array[j]=Array[j+1];
				Array[j+1]=temp;
			}
		}
	}
}

int			 compare		(const void* ,const void* ); 
void		 bubble_sort 	(int* ,int ,int(*pf)(const void* ,const void* ));
