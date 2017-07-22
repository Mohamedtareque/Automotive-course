// queues is first in first out 
typedef int QueueEntry ; 
#ifndef QueueEntry
#define MAXQUEUE 5
#endif
//=================================================================
typedef struct queue
{
	int front ; 
	int rear ;
	int size ; 
	QueueEntry entry[MAXQUEUE];
}Queue;
//===============================================================
void 		Append 				(QueueEntry , Queue*); 
void		Retrieve 			(QueueEntry *,Queue*);
void 		CreateQueue			(Queue*);
