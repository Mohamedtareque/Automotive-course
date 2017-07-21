#ifndef MAX_STACK
#define MAX_STACK 5
#endif

typedef int stackEntry ;


typedef struct stack
{
	int top ; 
	stackEntry entry[MAX_STACK]	;
}Stack;

void 	creatStack		(Stack *);
int 	push			(stackEntry,Stack *);
int		Pop				(stackEntry *, Stack *);
void	StackTop		(stackEntry *, Stack *);
