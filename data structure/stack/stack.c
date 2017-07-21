#include "stack.h"
#include <stdio.h>


// intializing stack through implementation level as top of stack has a garpage value 

void creatStack(Stack *ps)
{
	ps->top = 0 ;
}
// push function has two parameters the stackEntry datatype which relative to user selection 
// second parameter is a pointer to stack struct (pass by reference) as i wanna change the reference itself
// push mechanism is to push value at the top-1 of stack then increment top which has the posotion of next value 
int push(stackEntry e ,Stack *ps)
{
	/*
		preconditions : that stack have to be intialized and empty 
		post : that the top incremented by one position twords stack entryStack[stack.top++]
	*/
	if (ps->top == MAX_STACK)
	{
		return 0 ;
	}else{
		ps->entry[ps->top]= e; 
		ps->top++ ;
		//pe->stackEntry[ps->top++];
		return 1 ;
	}
}
// pop function 
int pop(stackEntry *pe,Stack *ps)
{
	if (ps->top==0)
	{
		return 0 ;
	}else{
		ps->top--;
		*pe = ps->entry[ps->top];
		return 1 ;
	}
	
}
// stackTop function 
void stackTop(stackEntry *pe , Stack *ps)
{
	if (ps->top!=0)
	{
		*pe = ps->entry[ps->top-1];// make a copy of the top element ,as element location at that moment has top val so we make top-- to get a vaild location 	
	}
}

// main function

int main(int argc, char *argv[])
{
	Stack s ; 
	stackEntry e ; 
	creatStack(&s);
	printf("Hello \n");
	
		printf("Enter your Item \n");
		scanf("%d",&e);
	
		/*
			preconditions : that stack have to be intialized and empty 
			post : that the top incremented by one position twords stack entryStack[stack.top++]
		*/
		push(e,&s);
		/*
			preconditions : that stack have to be intialized and non empty 
			post : that the top decreased by one position downwards stack entryStack[stack.top--]
			the last element is returned to entryStack
		*/
		//pop(&e,&s);
		/*	
			in some applications we need to make a copy of the top of stack without change of stack 
			just a copy from reference
		*/
		//stackTop(&e,&s);
		
	
	return 0 ;
	
}
