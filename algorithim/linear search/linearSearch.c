#include <stdio.h>
#include <stdlib.h>

#define N_MAX		10
#define TARGET 		40


//unsigned char search(unsigned char arr);

unsigned char search(unsigned char *arr)
{
		unsigned char i = 0 ;
		unsigned char index = *(arr+i) ;
//return index ;
		while(index!= 40)
		{
			i++ ;
			index = *(arr+i);

		}
		return i ;

}
int main(void) {
	unsigned char ARRAY[10]={55,6,8,99,7,5,1,2,40,21};
	char x = search(ARRAY);
	printf("%d \n",ARRAY[x]);
	printf("%d",x);
	return 0;
}

