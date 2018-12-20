#ifndef VECTOR_C
#define VECTOR_C
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector * newVector(){
	Vector * v = malloc(sizeof(Vector)+1);
	v->current_size = 0;
	v->max_size = 0;
	v->data = NULL;
	v->insert = insertVector;
	v->read = readVector;
	v->remove = removeVector;
	v->delete = deleteVector;
	return v;
}

void insertVector(struct Vector * v,int index, Data d){
	if(index >= v->max_size){
		v->max_size = index * 2+1;
		Data * new = malloc(sizeof(Data) * v->max_size); //allocated new space (temporarily)
		memset(new, -1, sizeof(Data)*v->max_size);
		memcpy(new,v->data, (sizeof(Data) * v->current_size)); //transferred the elements from the new array to the old array
		free(v->data); // delete or free up the old array
		v->data = NULL;
		v->data = new;	// assign it to the original array
	}

	if(index >= v->current_size){
		v->current_size = index+1;
	}
	v->data[index].value = d.value;
}

Data * readVector(struct Vector * v, int index){
	int count = 0;	
	if(index < v->current_size){
		for(int i=0; i<v->current_size;i++){ // for a different option of delete. count is the index for the valid elements.
			if(count == index){
				return &(v->data[i]);
			}
			else{
				count++;
			}
		}
	}
	else
		return NULL;
	if(v->data[index].value == 0)
		return &(v->data[index]);

	return NULL;
}

void removeVector(struct Vector * v, int index){
	if(index < v->max_size){
		memmove(&(v->data[index]),&(v->data[index+1]),sizeof(Data)*(--v->max_size-index));
		v->data=realloc(v->data,sizeof(Data)*v->max_size);
		if(index<v->current_size)
			v->current_size--;
	}	
}

void deleteVector(struct Vector * v){
	free(v->data);
	free(v);
}

#endif
