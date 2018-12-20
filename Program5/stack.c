#ifndef STACK_C
#define STACK_C
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top;

Stackvector * newStackvector(){
	Stackvector * sv = malloc(sizeof(Stackvector));
	top = 0;
	sv->data = newVector();
	sv->push = pushStackvector;
	sv->pop = popStackvector;
	sv->peek = peekStackvector;
	sv->clear = clearStackvector;
	sv->delete = deleteStackvector; 
	return sv;
}

void pushStackvector(Stackvector * sv, Data d){
	sv->data->insert(sv->data, top, d);
	top++;	
}

Data popStackvector(Stackvector * sv){
	if(sv->data->current_size == 0)
		return (Data){.value=-1};
	else{
		Data removed = * (sv->data->read(sv->data,sv->data->current_size-1));
		sv->data->remove(sv->data,sv->data->current_size-1);
		return removed;
	}
	
}

Data peekStackvector(Stackvector * sv){
		if(sv->data->current_size == 0)
			return (Data){.value=-1};
		else
			return * (sv->data->read(sv->data,sv->data->current_size-1));
	
}

void clearStackvector(Stackvector * sv){	
	for(int i=top;i>=0;i--){
		sv->pop(sv);
	}
}

void deleteStackvector(Stackvector * sv){
	sv->data->delete(sv->data);
	free(sv);
}

Stacklist * newStacklist(){
	Stacklist * sl = malloc(sizeof(Stacklist));
	sl->stacklength = 0;
	sl->data = newList();
	sl->push = pushStackList;
	sl->pop = popStackList;
	sl->peek = peekStackList;
	sl->clear = clearStackList;
	sl->delete = deleteStackList;

	return sl;
}

void pushStackList(Stacklist * s, Data d){
	int index = 0;
	s->data->insert(s->data, index, d);
	s->stacklength++;
}

Data popStackList(Stacklist * s){
	if(s->stacklength > 0)
	{	
		Data popped = s->data->tail->data;

		s->data->remove(s->data, s->stacklength-1);
		s->stacklength--;

		return popped;
	}
	else
	{
		return (Data){.value = -1};
	}
}

Data peekStackList(Stacklist * s){
	return s->data->tail->data;
}

void clearStackList(Stacklist * s){
	while(s->stacklength != 0){
		s->data->remove(s->data, s->stacklength-1);
		s->stacklength--;
	}
}

void deleteStackList(Stacklist * s){
	for(int i = 0; i < s->stacklength; i++){
		s->data->remove(s->data, i);
	}
	s->data->delete(s->data);
	s->data = NULL;
	free(s);
}

#endif

