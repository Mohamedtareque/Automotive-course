typedef int QueueEntry ; 

typedef struct queueNode
{
	QueueEntry entry ; 
	struct queueNode *next ;
}QueueNode;

typedef struct queue
{
	QueueNode *rear;
	QueueNode *front ;
	int size ;
}Queue;
//===============================================================
void 		Append 				(QueueEntry , Queue*); 
void		Retrieve 			(QueueEntry *,Queue*);
void 		CreateQueue			(Queue*);
