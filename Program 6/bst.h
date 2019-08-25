#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Data{
	int value;
}Data;

typedef struct Node{
	struct Data data;
	struct Node * left, * right, * parent;
}Node;

typedef struct Tree{
	struct Node * root;
	struct Data * (* insert)(struct Tree * t, Data d);
	void (* sort)(struct Tree * t, Data * d);
	struct Data * (* search)(struct Tree * t, Data d);
	struct Tree * (* clone)(struct Tree * t);
	int (* compare)(struct Tree *t, struct Tree * copy);
	void (* removeData)(struct Tree * bst, Data value);
	void (* delete)(struct Tree * bst);
	void (* traversal)(struct Node * n);
	
}Tree;

Node * newNode(Data d, Node * parent);
Data * insertNode(Node * n, Data d);
Data * readNode(Node * n, Data d);
Node * searchNodeHelper(Node * n, Data d);
void freeNode(Node * n);
Tree * newTree();
Data * insertTree(Tree * t, Data d);
void sortTree(Tree * t, Data * arr);
Data * searchTree(Tree * bst, Data d);
Tree * cloneTree(Tree * t);
int compareTree(Tree * t, Tree * new_t);
void removeTree(Tree * t, Data d);
void deleteTree(Tree * t);

int inOrder(Node * n, Data * arr, int index);
void preOrderClone(Node * n, Tree * t);
void preOrderCompare(Node * t_n, Node * new_t_n, int * val);
Node * searchNode(Tree * t, Data d);
void removeLeaf(Tree * t, Node * n);
void shortCircuit(Tree * t, Node * n);
void promotion(Tree * t, Node * n);
Node * searchRightMin(Node * n);
void postOrderDeletion(Tree * t, Node * n);
void inOrderTraversal(Node * n);

#endif
