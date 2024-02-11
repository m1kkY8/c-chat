#include "server.h"
#include <pthread.h>

void task_queue_init(task_queue_t **task_queue){
    pthread_mutex_init(&(*task_queue)->queue_lock, NULL); 
    pthread_cond_init(&(*task_queue)->queue_lock_signal, NULL);

    (*task_queue)->first = NULL;
    (*task_queue)->last = NULL;
}

void task_queue_destroy(task_queue_t **task_queue){
    
    pthread_mutex_destroy(&(*task_queue)->queue_lock); 
    pthread_cond_destroy(&(*task_queue)->queue_lock_signal);

    free_queue((*task_queue)->first);
}


void push(task_queue_t** queue, task_t *task){
    queue_t* new_node = NULL; 
    new_node = (queue_t*)malloc(sizeof(queue_t));
    check(new_node != NULL);

    new_node->task = task;
    new_node->head= NULL;

    if((*queue)->last){
        (*queue)->last->head = new_node;
    }

    (*queue)->last->head = new_node;

    if(!(*queue)->first){
        (*queue)->first = (*queue)->last;
    }

}

task_t* pop(task_queue_t** queue){
    queue_t* first = (*queue)->first;

    if(first == NULL)
        return NULL;

    queue_t* to_pop = NULL;
    task_t* task = NULL; 

    to_pop = first;
    task = first->task;
    first = first->head;

    free(to_pop);

    return task;
}

void print_queue(queue_t* queue){
    if(queue == NULL)
        return;

    queue_t* current = queue;
    while (current != NULL) {
        print_task(current->task);
        current = current->head;
    }

    printf("\n");
}

void print_task(task_t *task){
    if(task == NULL)
        return;

    printf("Task ID: %d, Task value: %d\n", task->task_id, task->val1 + task->val2);
}

void free_queue(queue_t* queue){
    while (queue != NULL) {
        queue_t* temp = queue;
        queue = queue->head;
        free(temp->task);
        free(temp);
    }
}

int is_empty(queue_t *queue){
    return (queue == NULL);
}
