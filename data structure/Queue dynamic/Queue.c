#include "Queue_d.h"
#include <stdlib.h>
void main(int argc, char const *argv[])
{
	
	Queue q ; 
	QueueEntry e ;
	CreatQueue(&q);
	Append(e,&q);
	Retrieve(&e,&q);
}

void CreatQueue(Queue *pq)
{
	pq->rear=NULL;
	pq->front=NULL;
	pq->size=0;
}

void Append(QueueEntry e , Queue *pq)
{
	QueueNode *pn = (QueueNode*)malloc(sizeof(QueueNode));
	pn->next=NULL;
	pn->entry = e ; 
	if (!pq->rear)
	{
		pq->front=NULL;
	}else
	{
		pq->rear->next=pn ;
	}
	pq->rear= pn ;
	pq->size++;
}

void Retrieve(QueueEntry *pe , Queue *pq)
{
	QueueNode *pn= pq->front ;
	*pe = pn->entry;
	pq->front=pn->next;
	free(pn);
	pq->size--;
}
