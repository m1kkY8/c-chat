#include "server.h"
#include <pthread.h>
#include <unistd.h>

#define NUM_OF_TASKS (100)
#define NUM_OF_THREADS (4)

task_queue_t* task_queue = NULL;

void* handle_task(void* arg){
    task_queue_t* queue = (task_queue_t*)arg;


    while(1){
        pthread_mutex_lock(&queue->queue_lock);

        while(is_empty(queue->first)){
            pthread_cond_wait(&queue->queue_lock_signal, &queue->queue_lock);
        }
        task_t* task = pop(&queue);

        print_task(task);
         
        free(task);
        
        pthread_mutex_unlock(&queue->queue_lock);
    }

    return NULL;
}

int main() {

    pthread_t* thread_pool = (pthread_t*)malloc(sizeof(pthread_t) * NUM_OF_THREADS);
    //task_queue_init(&task_queue);

    for(int i = 0; i < NUM_OF_TASKS; i++){
        task_t* new_task = (task_t*)malloc(sizeof(task_t));
        new_task->task_id = i;
        new_task->val1 = i * 3;
        new_task->val2 = i * 2;

        //push(&task_queue, new_task);
    } 

/*
    for(int i = 0; i < NUM_OF_THREADS; i++){
        pthread_create(&thread_pool[i], NULL, handle_task, &task_queue);
    }

    for(int i = 0; i < NUM_OF_THREADS; i++){
        pthread_join(thread_pool[i], NULL);
    }

    free(thread_pool);
    free(task_queue_first);
*/
    exit(0);
}
