#ifndef BST_C
#define BST_C
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Node * newNode(Data d, Node * parent){
	Node * n = malloc(sizeof(Node));
	n->left = NULL;
	n->right = NULL;
	n->parent = parent;
	n->data = d;
	return n;
}

Tree * newTree(){
	Tree * t = malloc(sizeof(Tree));
	t->root = NULL;
	t->insert = insertTree;
	t->search = searchTree;
	t->clone = cloneTree;
	t->sort = sortTree;
	t->compare = compareTree;
	t->removeData = removeTree;
	t->delete = deleteTree;
	t->traversal = inOrderTraversal;
	return t;
}

Data * insertTree(Tree * t, Data d){
	if(t->root == NULL){
		t->root = newNode(d,NULL);
		return &(t->root->data);
	}
	else{
		Data * temp = insertNode(t->root,d);
		return temp;
	}
}

Data * insertNode(Node * n, Data d){
	if(d.value < n->data.value){
		if(n->left == NULL){
			n->left = newNode(d,n);
			return &(n->left->data);
		}
		else{
			insertNode(n->left,d);
		}
	}
	else if(d.value > n->data.value){
		if(n->right == NULL){
			n->right = newNode(d,n);
			return &(n->right->data);
		}
		else{
			insertNode(n->right,d);
		}
	}
	else if(d.value == n->data.value){
		return NULL;
	}
}

Node * searchNode(Tree * t, Data d){
	if(t->root == NULL){
		return NULL;
	}
	else{
		return searchNodeHelper(t->root,d);
	}
}

Node * searchNodeHelper(Node * n, Data d){
	if(n->data.value == d.value){
		return n;
	}
	else if(d.value < n->data.value){
		if(n->left == NULL){
			return NULL;
		}
		else{
			return searchNodeHelper(n->left,d);
		}
	}
	else if(d.value > n->data.value){
		if(n->right == NULL){
			return NULL;
		}
		else {
			return searchNodeHelper(n->right,d);
		}
	}
}

void sortTree(Tree * t, Data * d){
	Node * n = t->root;
	int index = 0;
	Data * startPtr = d;

	if(n != NULL){
		index = inOrder(n,d,index);
	}
}

int inOrder(Node * n, Data * d, int index){
	if(n == NULL){
		return index--;
	}
	index = inOrder(n->left,d,index);
	d[index] = n->data;
	index++;
	index = inOrder(n->right,d,index);
}

Data * searchTree(Tree * t, Data d){
	if(t->root == NULL){
		return NULL;
	}
	return readNode(t->root,d);
}

Data * readNode(Node * n, Data d){
  if(n->data.value == d.value){
    return &(n->data);
  }else if(n->data.value < d.value){
    if(n->right == NULL){
      return NULL;
    }else{
      return readNode(n->right,d);
    }
  }else if(n->data.value > d.value){
    if(n->left == NULL){
      return NULL;
    }else{
      return readNode(n->left,d);
    }
  }  
}

Tree * cloneTree(Tree * bst){
  if(bst->root == NULL){
    return NULL;
  }
  Node * n = bst->root;
  Tree * new_tree = newTree();
  preOrderClone(n,new_tree);
  return new_tree;
}


void preOrderClone(Node * n, Tree * new_bst){
  if(n== NULL){
    return;
  }
  new_bst->insert(new_bst,n->data);
  preOrderClone(n->left,new_bst);
  preOrderClone(n->right,new_bst);
}


int compareTree(Tree * bst, Tree * bst1){
  if(bst == NULL && bst1 == NULL){
    return 1;
  }else if(bst == NULL || bst1 == NULL){
    return 0;
  }
  Node * n1 = bst->root;
  Node * n2 = bst1->root;
  int val = 0;
  preOrderCompare(n1,n2,&val);
  
   if(val == 0){
     
     return 1;
   }
  
   return 0;
}


void preOrderCompare(Node * n1, Node * n2, int * value){
  if(n1==NULL && n2==NULL){
    return;
  }else if(n1==NULL || n2==NULL){
    *value = 1;
    return;
  }
  if(n1->data.value != n2->data.value){
    *value = 1;
  }
  preOrderCompare(n1->left,n2->left,value);
  preOrderCompare(n1->right,n2->right,value);
}


void removeTree(Tree * bst, Data value){
  Node * toDelete = searchNode(bst,value);  
  if(toDelete != NULL){
    
    if(toDelete->left==NULL && toDelete->right==NULL){
      removeLeaf(bst,toDelete); 
    }else if(toDelete->left==NULL || toDelete->right==NULL){
      shortCircuit(bst,toDelete);
    }else{
      promotion(bst,toDelete);
    }    
  }
}

void removeLeaf(Tree * bst, Node * n){
  if(n == bst->root){
    bst->root = NULL;
  }else if(n == n->parent->left){
    n->parent->left = NULL;
    n->parent = NULL;
  }else{
    n->parent->right = NULL;
    n->parent = NULL;
  }
  freeNode(n);
}


void shortCircuit(Tree * bst,Node * n){
  if(n==bst->root){
    if(n->left !=NULL){
      bst->root = n->left;
      freeNode(n);
    }else{
      bst->root = n->right;
      freeNode(n);
    }
  }else if(n==n->parent->left){
    if(n->left != NULL){
      n->parent->left = n->left;
      n->left->parent = n->parent;
    }else{
      n->parent->left = n->right;
      n->right->parent = n->parent;
    }
    freeNode(n);
  }else{
    if(n->left !=NULL){
      n->parent->right = n->left;
      n->left->parent = n->parent;
    }else{
      n->parent->right = n->right;
      n->right->parent = n->parent;
    }
    freeNode(n);
  } 
}

void promotion(Tree * tree, Node * n){
  Node * rightMin = searchRightMin(n);
  n->data.value = rightMin->data.value;
  if(rightMin->left == NULL && rightMin->right == NULL){
    removeLeaf(tree,rightMin);
  }else shortCircuit(tree,rightMin);
}


Node * searchRightMin( Node * node){
  node = node->right ;
  while(node->left !=NULL){
    node = node->left;
  }
  return node;
}

void deleteTree(Tree * tree){
  while(tree->root != NULL){
    postOrderDeletion(tree,tree->root);
  }
  free(tree->root);
  free(tree);
}


void postOrderDeletion(Tree * tree,Node * n){
  if(n==NULL){
    return;
  }
  postOrderDeletion(tree,n->left);
  postOrderDeletion(tree,n->right);
  removeLeaf(tree,n);
}

void freeNode(Node * n){

  n->left = NULL;
  n->right = NULL;
  n->parent = NULL;
  
  free(n->left);
  free(n->right);
  free(n->parent);
  free(n);
}

void inOrderTraversal(Node * n){
  if(n==NULL){
    return;
  }
  inOrderTraversal(n->left);
  fprintf(stderr,"%d\n",n->data.value);
  inOrderTraversal(n->right);
}

#endif
