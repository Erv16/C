#ifndef LIST_H
#define LIST_H

typedef struct Data{
	int value;
}Data;

typedef struct Node{
	Data data;
	struct Node * next, * prev;
}Node;

typedef struct List{
	Node * head, * tail;
	void (*insert)(struct List *, int index, Data d);
	Data *(*read)(struct List *, int index);
	void (*remove)(struct List *, int index);
	void (*delete)(struct List *);
}List;

List * newList();
Node * newNode(Data d, Node * next, Node * prev);
void insertList(List * l, int index, Data d);
void deleteList(List * l);
Data * readList(List * l, int index);
void removeItem(List * l, int index);

#endif
