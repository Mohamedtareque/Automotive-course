int compare(int a , int b)
{
	
	return (a > b ? 1 : -1);
}

void bubble_sort(int *Array ,int size, int(*pf)(int,int) )
{
	int i ,j , temp ; 
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if(pf(Array[j],Array[j+1])>0)
			{
				temp = Array[j];
				Array[j]=Array[j+1];
				Array[j+1]=temp;
			}
		}
	}
}

int			 compare		(int ,int ); 
int			 bubble_sort 	(int* ,int ,int(*pf)(int,int));
