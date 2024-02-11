#include "server.h"

void task_queue_init(task_queue_t *task_queue){
    task_queue->front = NULL;
    task_queue->back = NULL;

    pthread_mutex_init(&task_queue->queue_lock, NULL); 
    pthread_cond_init(&task_queue->queue_lock_signal, NULL);
}

void task_queue_destroy(task_queue_t *task_queue){
    
    pthread_mutex_destroy(&(task_queue)->queue_lock); 
    pthread_cond_destroy(&(task_queue)->queue_lock_signal);

    free_queue((task_queue)->front);
}


void push(queue_t** front, queue_t** back, task_t* task){
    queue_t* new_node = NULL; 

    new_node = (queue_t*)malloc(sizeof(queue_t));
    check(new_node != NULL);
    
    new_node->task = task;
    new_node->next = NULL;

    if((*back)){
        (*back)->next = new_node;
    }

    (*back) = new_node;

    if(!(*front)){
        *front = *back;
    }

}

task_t* pop(queue_t** queue){

    if(*queue == NULL)
        return NULL;

    queue_t* to_pop = NULL;
    task_t* task = NULL; 

    to_pop = (*queue);
    task = (*queue)->task;
    (*queue) = (*queue)->next;

    free(to_pop);
    
    return task;
}

void print_queue(queue_t* queue){
    if(queue == NULL)
        return;

    queue_t* current = queue;
    while (current != NULL) {
        print_task(current->task);
        current = current->next;
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
        queue = queue->next;
        free(temp->task);
        free(temp);
    }
}

int is_empty(queue_t *queue){
    return (queue == NULL);
}
