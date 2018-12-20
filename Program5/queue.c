#ifndef QUEUE_C
#define QUEUE_C
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int front;
int rear1,rear2;

Queuevector * newQueuevector(){
	Queuevector * sv = malloc(sizeof(Queuevector));
	sv->data = newVector();
	sv->enqueue = pushQueuevector;
	sv->dequeue = popQueuevector;
	sv->peek = peekQueuevector;
	sv->clear = clearQueuevector;
	sv->delete = deleteQueuevector; 
	return sv;
}

void pushQueuevector(Queuevector * sv, Data d){	
	sv->data->insert(sv->data,sv->data->current_size, d);	
}

Data popQueuevector(Queuevector * sv){
	if(sv->data->current_size == 0){
		return (Data){.value=-1};
	}
	else{
		Data removed = * (sv->data->read(sv->data,0));
		sv->data->remove(sv->data,0);
		return removed;
	}
}

Data peekQueuevector(Queuevector * sv){
	if(sv->data->current_size == 0)
			return (Data){.value=-1};
		else{
			Data removed = * (sv->data->read(sv->data,0));
			return removed;
		}
}

void clearQueuevector(Queuevector * sv){
	while(sv->data->current_size != 0)
		sv->dequeue(sv);
	
}

void deleteQueuevector(Queuevector * sv){
	sv->data->delete(sv->data);
	free(sv);
}

Queuelist * newQueuelist(){
	Queuelist * ql = malloc(sizeof(Queuelist));
	ql->queuelength = 0;
	ql->data = newList();
	ql->enqueue = enqueueList;
	ql->dequeue = dequeueList;
	ql->peek = peekQueueList;
	ql->clear = clearQueueList;
	ql->delete = deleteQueueList;

	return ql;
}

void enqueueList(Queuelist * q, Data d){
	int index = 0;
	q->data->insert(q->data, index, d);
	q->queuelength++;
}

Data dequeueList(Queuelist * q){
	if(q->queuelength > 0)
	{	
		Data dequeued = q->data->head->data;

		q->data->remove(q->data, 0);
		q->queuelength--;

		return dequeued;
	}
	else
	{
		return (Data){.value = -1};
	}
}

Data peekQueueList(Queuelist * q){
	return q->data->head->data;
}

void clearQueueList(Queuelist * q){
	while(q->queuelength != 0){
		q->data->remove(q->data, 0);
		q->queuelength--;
	}
}

void deleteQueueList(Queuelist * q){
	for(int i = 0; i < q->queuelength; i++){
		q->data->remove(q->data, i);
	}
	q->data->delete(q->data);
	q->data = NULL;
	free(q);
}

#endif
