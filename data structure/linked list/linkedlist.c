#include <stdlib.h>
#include "linkedlist.h"

void createStack(Stack *ps)
{
	ps->top =NULL ;
}

void push(stackEntry e , Stack *ps)
{
	stackNode *pn = (stackNode *)malloc(sizeof(stackNode));
	pn->entry = e ;
	pn->next = ps->top; 
	ps->top = pn ;
}

void pop(stackEntry *pe , Stack *ps)
{
	stackNode *pn = ps->top;
	*pe = ps->top->entry ;
	ps->top= ps->top->next ;
	free(pn);
}

void clear(Stack *ps)
{
	while(ps->top)
	{
		stackNode *pn = ps->top; 
		free(ps->top);
		ps->top = pn->top->next;
	}
	ps->top =NULL;
}
void main(int argc, char const *argv[])
{
	Stack s ; 
	stackEntry e ; 
	
	return 0;
}
