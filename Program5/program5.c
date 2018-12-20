#include "stack.h"
#include "stack.h"
#include "queue.h"
#include "queue.h"
#include "vector.h"
#include "vector.h"
#include "list.h"
#include "list.h"
#include "profile.h"
#include "profile.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1
#define PRINTD(f,v) { if(DEBUG) fprintf(stderr, "%s:%d|\t("#v") "f"\n", __FILE__, __LINE__, v); }
#define PRINTT { if(DEBUG) fprintf(stderr, "%s:%d|\n", __FILE__, __LINE__); }
/********************************************************************/
/*    DO NOT ALTER ANY OF THE THE DRIVER CODE                       */
/********************************************************************/

int main(){
    int i = 0;
    srand(time(NULL));
    printf("\t-----------------------------------\n");
    printf("\t-          Part A: Vectors        -\n");
    printf("\t-----------------------------------\n");

    printf("\n\t=========Test #1: Creating your Vector===========\n\n");

    Vector *vect = newVector();
    assert(vect->current_size == 0);
    assert(vect->max_size == 0);
    assert(vect->data == NULL);
    printf("\n\t=========Test #1 Passed...            ===========\n\n");

    printf("\n\t=========Test #2: Inserting 20 random values into your Vector===========\n\n");
    //Insert Vector
    Data data_array[20];
    for(i = 0 ; i < 20 ; i++){
        data_array[i].value = (rand() % 20) + 1;
        vect->insert(vect, i, data_array[i]);
    }

    assert(vect->max_size == 31);
    assert(vect->current_size == 20);
    printf("\n\t=========Test #2 Passed...            ===========\n\n");

    printf("\n\t=========Test #3: Inserting values into out of bounds index===========\n\n");
    vect->insert(vect, 49, (Data){49});
    assert(vect->max_size == 99);
    assert(vect->current_size == 50);

    printf("\n\t=========Test #3 Passed...            ===========\n\n");

    printf("\n\t=========Test #4: Inserting values into out of bounds index===========\n\n");
    //tests outof bounds insert with expansion
    vect->insert(vect, 40, (Data){40});
    assert(vect->max_size == 99);
    assert(vect->current_size == 50);

    printf("\n\t=========Test #4 Passed...            ===========\n\n");

    printf("\n\t=========Test #5: Reading from your vector===========\n\n");

    for(i = 0 ; i < 20 ; i++){
        Data * d = vect->read(vect, i);
        fprintf(stderr, "%d %d\n",data_array[i].value, d->value );
        assert(data_array[i].value == d->value);
    }
    Data * d = vect->read(vect, 49);
    assert(49 == d->value);

    printf("\n\t=========Test #5 Passed...            ===========\n\n");

    printf("\n\t=========Test #6: Reading from unititialized vector index (should return -1)===========\n\n");

    d = vect->read(vect, 45);
    fprintf(stderr, "%d\n", d->value);
    assert(d->value == -1);

    printf("\n\t=========Test #6 Passed...            ===========\n\n");

    printf("\n\t=========Test #7: Attempting to read from out of bounds===========\n\n");

    d = vect->read(vect, 100);
    assert(d == NULL);

    printf("\n\t=========Test #7 Passed...            ===========\n\n");

    printf("\n\t=========Test #8: Remove elements from the vector ===========\n\n");

    //RemoveVector
    vect->remove(vect, 49);
    vect->remove(vect, 40);

    printf("\n\t=========Test #8 Passed...            ===========\n\n");

    printf("\n\t=========Test #9: Remove elements from the vector randomly ===========\n\n");

    while(vect->current_size){
        vect->remove(vect, (rand()%5));
    }
    vect->remove(vect, 50);
    printf("\n\t=========Test #9 Passed...            ===========\n\n");

    printf("\n\t=========Test #10: Delete the vector from memory ===========\n\n");

    vect->delete(vect);
    vect = NULL;

    printf("\n\t=========Test #10 Passed...            ===========\n\n");
    printf("\t-----------------------------------\n");
    printf("\t-          Part B: Lists        -\n");
    printf("\t-----------------------------------\n");

    printf("\n\t=========Test #11: Creating your Linked List===========\n\n");
    List * list = newList();
    assert(list->head == NULL && list->tail == NULL);
    printf("\n\t\tTest #11: Passed ...\n\n");

    printf("\n\t=========Test #12: Linked List Insertion===========\n\n");
    int index = 0;
    //add elements to the list
    for(index = 0 ; index < 10 ; index++ ){
        list->insert(list , index, (Data){index+1});
    }
    assert(list->head != NULL && list->tail != NULL);
    assert(list->head->next != NULL && list->head->prev == NULL);
    assert(list->tail->next == NULL && list->tail->prev != NULL);
    Node * test = list->head;
    for(index = 0 ; index < 10 ; index++, test = test->next){
        assert(test->data.value == index +1);
    }
    //***** Test that out of bounds indexes are appended to the list ****/
    list->insert(list , 20, (Data){11});
    assert(list->tail->data.value == 11);

    fprintf(stderr, "\n\t\tTest #12: Passed ...\n\n");

    printf("\n\t=========Test #13: Linked List Read===========\n\n");
    for(index = 0 ; index < 10 ; index++){
        Data * d = list->read(list, index);
        assert(d->value == index +1);
    }
    d = list->read(list, 20);
    assert(d == NULL);
    printf("\n\t\tTest #13: Passed ...\n\n");

    fprintf(stderr, "\n\t=========Test #14: Linked List Remove===========\n\n");

    for(index = 0; list->head != NULL; index++){
        index = index % 4;
        list->remove(list , index);
    }
    assert(list->head == NULL && list->tail == NULL);
    list->delete(list);
    list = NULL;
    fprintf(stderr, "\n\t\tTest #14 Passed...\n\n");

    fprintf(stderr, "\n\t=========Test #15: Stack Create ===========\n\n");
    Stacklist * sl = newStacklist();
    assert(sl->data->head == NULL);
    Stackvector * sv = newStackvector();
    assert(sv->data->current_size == 0);
    fprintf(stderr, "\n\t\tTest #15 Passed...\n\n");

    fprintf(stderr, "\n\t=========Test #16: Stack Push ===========\n\n");
    for(int i = 0; i < 10; i++){
        sl->push(sl, (Data){.value=i});
    }
    for(int i = 0, j = 9; i < 10; i++, j--){
        assert(sl->data->read(sl->data, i)->value == i || sl->data->read(sl->data, i)->value == j);
    }

    for(int i = 0; i < 10; i++){
        sv->push(sv, (Data){.value=i});
    }
    for(int i = 0, j = 9; i < 10; i++, j--){
        assert(sv->data->read(sv->data, i)->value == i || sv->data->read(sv->data, i)->value == j);
    }
    fprintf(stderr, "\n\t\tTest #16 Passed...\n\n");

    fprintf(stderr, "\n\t=========Test #17: Stack Pop ===========\n\n");
    for(int i = 9; i >= 0; i--){
        Data d = sl->pop(sl);
        assert(d.value == i);
    }
    for(int i = 9; i >= 0; i--){
        Data d = sv->pop(sv);
        assert(d.value == i);
    }
    fprintf(stderr, "\n\t\tTest #17 Passed...\n\n");

    fprintf(stderr, "\n\t=========Test #18: Stack Peek ===========\n\n");
    //TODO check to make sure I can pop empty
    for(int i = 0; i < 10; i++){
        sl->push(sl, (Data){.value=i});
    }
    for(int i = 9; i >= 0; i--){
        Data d = sl->peek(sl);
        assert(d.value == i);
        d = sl->peek(sl);
        assert(d.value == i);
        sl->pop(sl);
    }

    for(int i = 0; i < 10; i++){
        sv->push(sv, (Data){.value=i});
    }
    for(int i = 9; i >= 0; i--){
        Data d = sv->peek(sv);
        assert(d.value == i);
        d = sv->peek(sv);
        assert(d.value == i);
        sv->pop(sv);
    }
    fprintf(stderr, "\n\t\tTest #18 Passed...\n\n");

    fprintf(stderr, "\n\t=========Test #19: Stack Clear ===========\n\n");
    for(int i = 0; i < 10; i++){
        sl->push(sl, (Data){.value=i});
    }
    sl->clear(sl);
    assert(sl->pop(sl).value == -1);
    for(int i = 0; i < 10; i++){
        sv->push(sv, (Data){.value=i});
    }
    sv->clear(sv);
    assert(sv->pop(sv).value == -1);
    fprintf(stderr, "\n\t\tTest #19 Passed...\n\n");

    fprintf(stderr, "\n\t=========Test #20: Stack Delete ===========\n\n");
    sl->delete(sl);
    sv->delete(sv);
    fprintf(stderr, "\n\t\tTest #20 Passed (but check valgrind to be sure)...\n\n");

    fprintf(stderr, "\n\t=========Test #21: Queue Create ===========\n\n");
    Queuelist * ql = newQueuelist();
    assert(ql->data->head == NULL);
    Queuevector * qv = newQueuevector();
    assert(qv->data->current_size == 0);
    fprintf(stderr, "\n\t\tTest #21 Passed...\n\n");

    fprintf(stderr, "\n\t=========Test #22: Queue Enqueue ===========\n\n");
    for(int i = 0; i < 10; i++){
        ql->enqueue(ql, (Data){.value=i});
    }
    for(int i = 0, j = 9; i < 10; i++, j--){
        assert(ql->data->read(ql->data, i)->value == i || ql->data->read(ql->data, i)->value == j);
    }
    for(int i = 0; i < 10; i++){
        qv->enqueue(qv, (Data){.value=i});
    }
    for(int i = 0, j = 9; i < 10; i++, j--){
        assert(qv->data->read(qv->data, i)->value == i || qv->data->read(qv->data, i)->value == j);
    }
    fprintf(stderr, "\n\t\tTest #22 Passed...\n\n");

    fprintf(stderr, "\n\t=========Test #23: Queue Dequeue ===========\n\n");
    for(int i = 0; i < 10; i++){
        Data d = ql->dequeue(ql);
        assert(d.value == i);
    }
    for(int i = 0; i < 10; i++){
        Data d = qv->dequeue(qv);
        assert(d.value == i);
    }
    fprintf(stderr, "\n\t\tTest #23 Passed...\n\n");

    fprintf(stderr, "\n\t=========Test #24: Queue Peek ===========\n\n");
    for(int i = 0; i < 10; i++){
        ql->enqueue(ql, (Data){.value=i});
    }
    for(int i = 0; i < 10; i++){
        Data d = ql->peek(ql);
        assert(d.value == i);
        d = ql->peek(ql);
        assert(d.value == i);
        d = ql->dequeue(ql);
    }
    for(int i = 0; i < 10; i++){
        qv->enqueue(qv, (Data){.value=i});
    }
    for(int i = 0; i < 10; i++){
        Data d = qv->peek(qv);
        assert(d.value == i);
        d = qv->peek(qv);
        assert(d.value == i);
        qv->dequeue(qv);
    }
    fprintf(stderr, "\n\t\tTest #24 Passed...\n\n");

    fprintf(stderr, "\n\t=========Test #25: Queue Clear ===========\n\n");
    for(int i = 0; i < 10; i++){
        ql->enqueue(ql, (Data){.value=i});
    }
    ql->clear(ql);
    assert(ql->dequeue(ql).value == -1);
    for(int i = 0; i < 10; i++){
        qv->enqueue(qv, (Data){.value=i});
    }
    qv->clear(qv);
    assert(qv->dequeue(qv).value == -1);
    fprintf(stderr, "\n\t\tTest #25 Passed...\n\n");

    fprintf(stderr, "\n\t=========Test #26: Queue Delete ===========\n\n");
    ql->delete(ql);
    qv->delete(qv);
    fprintf(stderr, "\n\t\tTest #26 Passed (but check valgrind to be sure)...\n\n");

    printf("\n\t========= Speed Tests ===========\n\n");

    printf("Comparing Stacks and Queues used with Vector and Lists\n");
    sl = newStacklist();
    sv = newStackvector();
    ql = newQueuelist();
    qv = newQueuevector();
    profileStack(sv, sl);
    profileQueue(qv, ql);
    sl->delete(sl);
    sv->delete(sv);
    ql->delete(ql);
    qv->delete(qv);
    printf("\n\t========= Don't forget to submit your hash and check your code with Valgrind! ===========\n\n");

    return 0;
}
