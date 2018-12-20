#include "profile.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>/* timeval, gettimeofday() */

void profileStack(Stackvector * sv, Stacklist *sl){
    printf("\tBeginning Stackvector push profile time");
    struct timeval start, stop;
    gettimeofday(&start, NULL);

    for(int i = 0; i< 1000; i++){
        sv->push(sv, (Data) {i});
    }
    gettimeofday(&stop, NULL);
    time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
    time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    float profile_time = stop_time - start_time;
    printf("\tCompleted Stackvector push profile time = %lf\n", profile_time);
    printf("\tBeginning Stacklist push profile time");
    gettimeofday(&start, NULL);

    for(int i = 0; i< 1000; i ++){
        sl->push(sl, (Data) {i});
    }
    gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = (float)stop_time - (float)start_time;
    printf("\tCompleted Stacklist push profile time = %lf\n", profile_time);
    printf("\tBeginning Stackvector pop profile time");
    gettimeofday(&start, NULL);
    for(int i = 0; i< 1000; i++){
        sv->pop(sv);
    }
    gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = stop_time - start_time;
    printf("\tCompleted Stackvector pop profile time = %lf\n", profile_time);
    printf("\tBeginning Stacklist pop profile time");
    gettimeofday(&start, NULL);

    for(int i = 0; i< 1000; i++){
        sl->pop(sl);
    }
    gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = stop_time - start_time;
    printf("\tCompleted Stacklist pop profile time = %lf\n", profile_time);
}

void profileQueue(Queuevector * sv, Queuelist *sl){
    printf("\tBeginning Queuevector enqueue profile time");
    struct timeval start, stop;
    gettimeofday(&start, NULL);

    for(int i = 0; i< 1000; i++){
        sv->enqueue(sv, (Data) {i});
    }
    gettimeofday(&stop, NULL);
    time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
    time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    float profile_time = stop_time - start_time;
    printf("\tCompleted Queuevector enqueue profile time = %lf\n", profile_time);
    printf("\tBeginning Queuelist enqueue profile time");
    gettimeofday(&start, NULL);

    for(int i = 0; i< 1000; i ++){
        sl->enqueue(sl, (Data) {i});
    }
    gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = stop_time - (float)start_time;
    printf("\tCompleted Queuelist enqueue profile time = %lf\n", profile_time);
    printf("\tBeginning Queuevector dequeue profile time");
    gettimeofday(&start, NULL);
    for(int i = 0; i< 1000; i++){
        sv->dequeue(sv);
    }
    gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = stop_time - start_time;
    printf("\tCompleted Queuevector dequeue profile time = %lf\n", profile_time);
    printf("\tBeginning Queuelist dequeue profile time");
    gettimeofday(&start, NULL);

    for(int i = 0; i< 1000; i++){
        sl->dequeue(sl);
    }
    gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = stop_time - start_time;
    printf("\tCompleted Queuelist dequeue profile time = %lf\n", profile_time);
}
