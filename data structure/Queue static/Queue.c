#include "queue.h"
#include <stdlib.h>

void main(int argc, char const *argv[])
{
	Queue q ; 
	QueueEntry e ; 
	CreatQueue(&q);
	Append(e,&q);
}

void CreatQueue(Queue *pq)
{
	pq->front = 0 ;
	pq->rear = -1 ;
	pq->size = 0 ;
}

void Append(QueueEntry e , Queue *pq)
{
	if (pq->rear == MAXQUEUE)
	{
		pq->rear = 0
	}
	else
	{
    	pq->entry[pq->rear] = e ; 
		pq->rear++ ;
		pq->size++ ;
	}

}	

void Retrieve(QueueEntry *pe ,Queue *pq)
{
	*pe = pq->entry[pq->front];
	pq->size-- ;
}
