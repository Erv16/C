#ifndef STACK_H
#define STACK_H
#include "vector.h"
#include "list.h"

typedef struct Stacklist
{
	int stacklength;
	List * data;
	void (*push)(struct Stacklist *, Data);
	Data (*pop)(struct Stacklist *);
	Data (*peek)(struct Stacklist *);
	void (*clear)(struct Stacklist *);
	void (*delete)(struct Stacklist *);
}Stacklist;

Stacklist * newStacklist();
void pushStackList(struct Stacklist *, Data);
Data popStackList(struct Stacklist *);
Data peekStackList(struct Stacklist *);
void clearStackList(struct Stacklist *);
void deleteStackList(struct Stacklist *);

typedef struct Stackvector{
	Vector * data;
	void (* push)(struct Stackvector * sv, Data d);
	Data (* peek)(struct Stackvector * sv);
    	Data (* pop)(struct Stackvector * sv);
    	void (* clear)(struct Stackvector * sv);
    	void (* delete)(struct Stackvector * sv);
}Stackvector;

Stackvector * newStackvector();
void pushStackvector(struct Stackvector * sv, Data d);
Data popStackvector(struct Stackvector * sv);
Data peekStackvector(struct Stackvector * sv);
void clearStackvector(struct Stackvector * sv);
void deleteStackvector(struct Stackvector * sv);

#endif

