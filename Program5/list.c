#ifndef LIST_C
#define LIST_C
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List * newList(){
	List * l = malloc(sizeof(List));
	l->head = l->tail = NULL;
	l->insert = insertList;
	l->delete = deleteList;
	l->remove = removeItem;
	l->read = readList;
	return l;
}

Node * newNode(Data d, Node * next, Node * prev){
	Node * new_node = malloc(sizeof(Node));
	new_node->data = d;
	new_node->next = NULL;
	new_node->prev = prev;

	return new_node;
}

void insertList(List * l, int index, Data d){
	if(l->head == NULL)
	{
		l->head = newNode(d, NULL, NULL);
		l->tail = l->head;
	}
	else
	{
		Node * p = l->tail;
		p->next = newNode(d, NULL, p);
		l->tail = p->next;
	}
}

Data * readList(List * l, int index){
	Node * read_node = l->head;
	int count = 0;
	while(read_node != NULL){
		if(count == index){
			return &read_node->data;
		}
		count++;
		read_node = read_node->next;
	}

	return 0;
}

void removeItem(List * l, int index){
	Node * head_node = l->head;
	Node * remove_node = l->head;
	int count = 0;

	while(remove_node != NULL){

		if(count == index){
			if(l->head == l->tail){
				free(head_node);
				l->head = l->tail = NULL;
				break;
			}

			if(head_node == remove_node){
				head_node = remove_node->next;
				l->head = head_node;
			}

			if(remove_node->next == NULL){
				l->tail = remove_node->prev; 
			}

			if(remove_node->next != NULL){
				remove_node->next->prev = remove_node->prev;
			}

			if(remove_node->prev != NULL){
				remove_node->prev->next = remove_node->next;
			}

			free(remove_node);
			break;

		}
		count++;
		remove_node = remove_node->next;
	}
}

void deleteList(List * l){
	free(l);
}

#endif
