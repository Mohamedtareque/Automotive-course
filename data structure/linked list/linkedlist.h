typedef struct stacknode
{
	stackEntry entry ;
	struct stacknode *next ;
}stackNode;

//=============================================

typedef struct stack
{
	stackNode *top;
}Stack;

typedef int stackEntry ; 

//============================================
void 	creatStack		(Stack *);
void 	push			(stackEntry,Stack *);
void	Pop				(stackEntry *, Stack *);
void	clearStack		(Stack *);
