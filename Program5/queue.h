#ifndef QUEUE_H
#define QUEUE_H
#include "vector.h"
#include "list.h"

typedef struct Queuelist
{
	int queuelength;
	List * data;
	void (*enqueue)(struct Queuelist *, Data);
	Data (*dequeue)(struct Queuelist *);
	Data (*peek)(struct Queuelist *);
	void (*clear)(struct Queuelist *);
	void (*delete)(struct Queuelist * q);
}Queuelist;

Queuelist * newQueuelist();
void enqueueList(struct Queuelist *, Data);
Data dequeueList(struct Queuelist *);
Data peekQueueList(struct Queuelist *);
void clearQueueList(struct Queuelist *);
void deleteQueueList(struct Queuelist *);

typedef struct Queuevector{
	Vector * data;
	void (* enqueue)(struct Queuevector * sv, Data d);
	Data (* peek)(struct Queuevector * sv);
    	Data (* dequeue)(struct Queuevector * sv);
    	void (* clear)(struct Queuevector * sv);
    	void (* delete)(struct Queuevector * sv);
}Queuevector;

Queuevector * newQueuevector();
void pushQueuevector(struct Queuevector * sv, Data d);
Data popQueuevector(struct Queuevector * sv);
Data peekQueuevector(struct Queuevector * sv);
void clearQueuevector(struct Queuevector * sv);
void deleteQueuevector(struct Queuevector * sv);

#endif

