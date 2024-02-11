#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define PORT 1337

#define amogus printf("amogus\n");

#define check(cond)                                                      \
do {                                                                       \
    if (!(cond)) {                                                         \
        fprintf(stderr, "File: %s, line: %d\n", __FILE__, __LINE__);       \
        exit(1);                                                           \
    }                                                                      \
} while (0)

typedef struct Task{
    unsigned task_id;
    int val1;    
    int val2;    
    int sleep_second;
} task_t;

typedef struct Queue{
    task_t* task;
    struct Queue* head;
} queue_t;

typedef struct Task_Queue{
    queue_t* first;
    queue_t* last;
    pthread_cond_t queue_lock_signal;
    pthread_mutex_t queue_lock;

} task_queue_t;

void task_queue_init(task_queue_t** task_queue);
void task_queue_destroy(task_queue_t** task_queue);

void print_queue(queue_t* queue);
void print_task(task_t* task);

void push(task_queue_t** queue, task_t* task);
task_t* pop(task_queue_t** queue);
void free_queue(queue_t* queue);
int is_empty(queue_t* queue);
